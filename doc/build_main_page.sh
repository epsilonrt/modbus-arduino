#!/bin/sh
# (c) Copyright 2011-2016 epsilonRT, All rights reserved.

TARGET=main_page.dox

README=../README.md

PARSER=cat
command -v markdown >/dev/null 2>&1 && PARSER=markdown
# echo "PARSER=$PARSER"
if [ "$PARSER" = "markdown" ]; then
  HEAD_TAG="@htmlonly"
  FOOT_TAG="@endhtmlonly"
fi

cat main_page_header.dox > $TARGET

# README
echo "$HEAD_TAG" >> $TARGET
tail -n +6 $README | ${PARSER}  >> $TARGET
echo "$FOOT_TAG" >> $TARGET

cat main_page_footer.dox >> $TARGET
