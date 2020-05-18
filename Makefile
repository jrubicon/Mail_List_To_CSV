all: run_test

run_test: MailConv
	./MailConv exportlistexample.txt

MailConv: ConvertMailList.cpp
	g++ -std=c++14 ConvertMailList.cpp -o MailConv
