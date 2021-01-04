#Create the directories
mkdir TXT
mkdir JPG
mkdir ZIP
#Extract input.tar.gz
tar xzvf input.tar.gz
#Move the files with .txt extension to TXT
mv input/*.txt TXT
#Move the files with .jpg extension to TXT
mv input/*.jpg JPG
#Move the rest of files to ZIP
mv input/* ZIP/
#Compress ZIP directory
tar czf rest_zipped.tar.gz ZIP