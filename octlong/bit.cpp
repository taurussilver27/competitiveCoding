#include <iostream>
#include <algorithm>
#define DEBUG(X) cout << X << endl;
using namespace std;

long long int a[1601][6];
long long int b[1601][3];
int main(int argc, char const *argv[])
{
	
	int T;
	cin >> T;
	for(int i = 0; i <= 1600; ++i) for(int j = 0; j < 6; ++j) a[i][j] = 0;
	a[0][0] = 1;
	for(int i = 1; i <= 1600; ++i)
	{
		if(i-16 >= 0) a[i][0] = 2*a[i-16][4];
		if(i-2 >= 0) a[i][1] = a[i-2][0];
		if(i-2 >= 0) a[i][2] = a[i-2][0];
		if(i-8 >= 0) a[i][3] = a[i-8][2];
		if(i-8 >= 0) a[i][4] = a[i-8][2];
		if(i-16 >= 0) a[i][5] = a[i-16][4];
	}

	b[0][0] = 1;
	b[0][1] = 0;
	b[0][2] = 0;

	for(int i = 1; i <= 1600; ++i)
	{
		b[i][0] = b[i-1][0] + a[i][0] - a[i][1];
		b[i][1] = b[i-1][1] + a[i][2] - a[i][3];
		b[i][2] = b[i-1][2] + a[i][4] - a[i][5];
		

	}

	for(int Ti = 0; Ti < T; ++Ti)
	{
		int n;
		cin >> n;
		cout << b[n-1][0] << " "<< b[n-1][1] << " " << b[n-1][2] << endl;
	}
	return 0;
}