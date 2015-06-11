#include "popcut.h"
#include "ui_popcut.h"
#include <QDropEvent>
#include <QMimeData>

#include <QtWin>

#include <QGuiApplication>
#include <QScopedArrayPointer>
#include <QStringList>
#include <QPixmap>
#include <QImage>
#include <QFileInfo>
#include <QDir>
#include <iostream>

#include <QFileIconProvider>

popCut::popCut(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::popCut)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

popCut::~popCut()
{
    delete ui;
}

void popCut::dragEnterEvent(QDragEnterEvent *event)
{
    //event->setDropAction(Qt::IgnoreAction);
    event->accept();
}

void popCut::dropEvent(QDropEvent *event)
{
    // check for our needed mime type, here a file or a list of files
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls())
    {
        QList<QUrl> urlList = mimeData->urls();
        QString filenames = urlList.at(0).toLocalFile();

        QString url = filenames; //"C:\\MinGW\\libexec\\mingw-get\\guistub.exe"; //urlList.at(i).path();
//QString test = url.utf16();
QString test2 = url.toHtmlEscaped();

        HICON big;
        HICON smal;

        //const int iconCount = ExtractIconEx((wchar_t *)url.utf16(), -1, 0, 0, 0);
        const int iconCount = ExtractIconEx((wchar_t *)url.utf16(), -1, 0,0 , 0);

        if (!iconCount)
        {
            std::cerr << filenames.toStdString() << " does not appear to contain icons.\n";
            return;// 1;
        }
        QScopedArrayPointer<HICON> icons(new HICON[iconCount]);


        //const UINT extractedIconCount = ExtractIconEx((wchar_t *)url.utf16(), 0, 0, icons.data(), iconCount);
        const UINT extractedIconCount = ExtractIconEx((wchar_t *)url.utf16(), 0, icons.data(), 0, iconCount);

        if (!extractedIconCount)
        {
            qErrnoWarning("Failed to extract icons from %s", qPrintable(filenames));
            return;// 1;
        }

        std::cout << filenames.toStdString() << " contains " << extractedIconCount << " icon(s).\n";


        const QPixmap pixmap = QtWin::fromHICON(icons[0]);

        if (pixmap.isNull())
        {
            std::cerr << "Error converting icons.\n";
            return;
        }
        const QString fileName = QString("hopi.png");
        if (!pixmap.save(fileName))
        {
            std::cerr << "Error writing image file " << fileName.toStdString() << ".\n";
            return;
        }
    }
}

