#include <iostream>
#include <algorithm>
#define DEBUG(X) cout << X << endl;
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for(int Ti = 0; Ti < T; ++Ti)
	{
		int p1,p2,k;
		cin >> p1 >> p2 >> k;
		int x = ((p1 + p2)/k)%2;
		if(x == 0) cout << "CHEF" << endl;
		else cout << "COOK" << endl;
	}
	return 0;
}