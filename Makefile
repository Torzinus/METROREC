all:
	gcc -o sync_car sync_car.c sync_car-runner.c

clean:
	rm -f sync_car