#!/bin/bash
#find ./task-2/t -type f -name '*.c'| xargs gtar --transform 's/.*\///g' -zcvf allfile.tar

find . -type f -name "*.c"| xargs tar "--transform=s|.*/||g" -rf allcfiles.tar