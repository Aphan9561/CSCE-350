# makefile for project

compile: Phan_Anna_QuickSort.cpp
	g++ -Wall -std=c++11 Phan_Anna_QuickSort.cpp -o quickSort 

ten: Phan_Anna_QuickSort.cpp
	g++ -Wall -std=c++11 Phan_Anna_QuickSort.cpp -o quickSort 
	./quickSort input-10.txt output-10.txt

hundred: Phan_Anna_QuickSort.cpp
	g++ -Wall -std=c++11 Phan_Anna_QuickSort.cpp -o quickSort 
	./quickSort input-100.txt output-100.txt

thousand: Phan_Anna_QuickSort.cpp
	g++ -Wall -std=c++11 Phan_Anna_QuickSort.cpp -o quickSort
	./quickSort input-1000.txt output-1000.txt 

inputFileGenerator: InputFileGenerator.cpp
	g++ -Wall -std=c++11 InputFileGenerator.cpp -o generator
	./generator

clean:
	rm quickSort generator input_*_*.txt
