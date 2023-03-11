#!/bin/sh

YTD_DIR=~/.local/share/YTDownload/

## 1. Create directories, if does not exist
mkdir -p ${YTD_DIR}/{bin,config}


## 2. Download yt-dlp

if [ -e ${YTD_DIR}/bin/yt-dlp ]
then
    echo "yt-dlp exists"
else
    echo "Downloading yt-dlp"
    curl https://github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp --output $YTD_DIR/bin/yt-dlp
    chmod +x $YTD_DIR/bin/yt-dlp
fi
