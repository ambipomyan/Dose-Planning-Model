default:
	g++ -Wall -g -c Dp-init.cpp -o Dp-init.o
	g++ -Wall -g -c Dp-util.cpp -o Dp-util.o
	g++ -Wall -g -c Dp-cell.cpp -o Dp-cell.o
	g++ -std=c++11 Dp-test.cpp Dp-util.o Dp-cell.o Dp-init.o -I/usr/local/include/opencv4 -o test -lm -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs
run:
	./test
clean:
	rm test pred*.jpg *.o
