#!/bin/bash

# 检查参数数量
if [ "$#" -ne 2 ]; then
    echo "error：need two argument"
    exit 1
fi

filesdir=$1
searchstr=$2

# 检查filesdir是否是一个目录
if [ ! -d "$filesdir" ]; then
    echo "error：$filesdir is not dir"
    exit 1
fi

# 计算文件数和匹配行数
file_count=$(find "$filesdir" -type f | wc -l)
match_count=$(grep -r "$searchstr" "$filesdir" | wc -l)

# 打印结果
echo "The number of files are $file_count and the number of matching lines are $match_count"
