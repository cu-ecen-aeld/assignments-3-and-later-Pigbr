#!/bin/bash

# 检查参数数量
if [ "$#" -ne 2 ]; then
    echo "error：need two argument"
    exit 1
fi

writefile=$1
writestr=$2

# 创建文件路径
mkdir -p "$(dirname "$writefile")"

# 写入内容到文件
echo "$writestr" > "$writefile"

# 检查文件是否创建成功
if [ $? -ne 0 ]; then
    echo "error：cant make $writefile"
    exit 1
fi
