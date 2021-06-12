//#include "DLL.h"
#include "LRUReplacement.h"
#include<iostream>
using namespace std;



int main()
{
	int MAX = 13;
	LRUReplacement Stack1(13);
	int RefString [13] = {4,7,0,7,1,0,1,2,1,2,7,1,2};
	for (int i = 0; i < MAX; i++)
	{
		cout << "REFERENCE: " << RefString[i] << endl;
		cout << "Before" << endl;
		Stack1.displayAll();
		Stack1.newReference(RefString[i]);
		cout << "After" << endl;
		Stack1.displayAll();
	}

	cout << endl << "getVictim" << endl;
	cout << "Before" << endl;
	Stack1.displayAll();
	cout << "Victim: " << Stack1.getVictimPage() << endl;
	cout << "After" << endl;
	Stack1.displayAll();

	cout << endl << "getVictim" << endl;
	cout << "Before" << endl;
	Stack1.displayAll();
	cout << "Victim: " << Stack1.getVictimPage() << endl;
	cout << "After" << endl;
	Stack1.displayAll();
	Stack1.displayAllBackwards();

	//Stack1.printEnds();

	/*DLL Stack1;

	Stack1.addRear(1);
	Stack1.addRear(2);
	Stack1.addRear(3);
	Stack1.addRear(4);

	Stack1.displayAll();
	Stack1.displayAllBackwards();
	cout << endl;

	Stack1.moveNodeToBack(1);

	Stack1.displayAll();
	Stack1.displayAllBackwards();
	cout << endl;

	Stack1.moveNodeToBack(4);

	Stack1.displayAll();
	Stack1.displayAllBackwards();
	cout << endl;

	Stack1.moveNodeToBack(2);

	Stack1.displayAll();
	Stack1.displayAllBackwards();
	cout << endl;*/


}
