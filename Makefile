default: 
	g++ -o passCracker passCracker.cc
	./passCracker
	g++ -o passCracker2 passCracker2.cc
	./passCracker2	

clean:
	rm -f *.txt *.csv passCracker