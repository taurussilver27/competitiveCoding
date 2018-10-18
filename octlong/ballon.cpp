#include <iostream>
#include <algorithm>
#include <queue>
#define DEBUG(X) cout << X << endl;
#define LL long long int
using namespace std;


long long int a[100000 + 1];
long long int b[100000 + 1];


class mycmp{
public:
	bool operator()(int & i, int & j)
	{
		return a[i]*b[i] < a[j]*b[j];
	}
};

int main(int argc, char const *argv[])
{
	a[100000] = 0;
	b[100000] = 0;
	LL n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	priority_queue<int, vector<int>, mycmp> q;
	// priority_queue<int, vector<int>, [&](int & i, int & j){return a[i]*b[i] < a[j]*b[j];}> q;

	for(int i = 0; i < n; ++i) q.push(i);

	int temp;
	int temp2;
	long long int c;
	LL bl;
	while(m > 0 && !q.empty())
	{
		temp = q.top();
		// DEBUG(temp << " " <<a[temp]*b[temp])
		q.pop();
		if(q.empty()) temp2 = 1e5;
		else temp2 = q.top();
		c = a[temp]*b[temp] - a[temp2]*b[temp2];
		bl = min(a[temp],min(m,c/b[temp] + 1));
		a[temp] -= bl;
		m -= bl;
		if(a[temp] != 0) q.push(temp);
	}

	if(q.empty()) cout << 0 << endl;
	else cout << a[q.top()]*b[q.top()] << endl;

	return 0;
}