default: 
	g++ -o passCracker passCracker.cc
	./passCracker

clean:
	rm -f *.txt *.csv passCracker