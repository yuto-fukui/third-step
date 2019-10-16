#! /usr/bin/env ruby
require "numo/narray"

science = Numo::DFloat[65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 2, 58.5, 46, 42, 78, 62, 84, 70]
english = Numo::DFloat[44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

printf("理科・・・平均：%f, 標準偏差：%f, 合計：%f\n",science.mean, science.stddev, science.sum)
printf("英語・・・平均：%f, 標準偏差：%f, 合計：%f\n",english.mean, english.stddev, english.sum)

for i in 0..19
	shen = (science[i] - science.mean) / science.stddev * 10.0 + 50.0
	ehen = (english[i] - english.mean) / english.stddev * 10.0 + 50.0

	printf("%d番の偏差値・・・理科：%f, 英語：%f\n",i+1, shen, ehen)
end

print("理科の降順ソート")
science=science.sort
p science.reverse
print("英語の降順ソート")
english = english.sort
p english.reverse
