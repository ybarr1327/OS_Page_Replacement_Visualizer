#include "lruAlgo.h"

using namespace std;

const int MAX = 13;

int main()
{
	lruAlgo l1(MAX);
	int RefString[MAX] = {1,2,3,4,1,2,5,1,2,3,4,5};
	for (int i = 0; i < MAX; i++)
	{
		/*cout << "REFERENCE: " << RefString[i] << endl;

		cout << "Before" << endl;
		l1.printContents();*/

		l1.updateCount(RefString[i]);

		/*cout << "After" << endl;
		l1.printContents();
		cout << endl;*/
	}

	/*cout << "Take Victim" << endl;
	cout << "Before" << endl;
	l1.printContents();

	int victim = l1.getVictim();

	cout << "After" << endl;
	l1.printContents();
	cout << "victim: " << victim << endl;
	cout << endl;*/
}