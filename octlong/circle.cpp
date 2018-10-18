#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#define DEBUG(X) cout << X << endl;
#define LL long long int
using namespace std;
#define SIZE 2000000

long long int a[1000 + 1][3];
LL mn[1000 + 1][1000+1];
LL mx[1000 + 1][1000+1];

LL cir[SIZE];

int main(int argc, char const *argv[])
{
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; ++i)
	{
		// cin >> a[i][0] >> a[i][1] >> a[i][2];
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
	}
	double dis;
	long long int r,R;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i+1; j < n; ++j)
		{
			dis = pow((double)((a[i][0]-a[j][0])*(a[i][0]-a[j][0]) + (a[i][1]-a[j][1])*(a[i][1]-a[j][1])),0.5);
			if(a[i][2] < a[j][2]){r = a[i][2]; R = a[j][2];}
			else {r = a[j][2]; R = a[i][2];}
			if(dis + r < R)
			{
				mn[i][j] = ceil(R - r- dis);
				mx[i][j] = R + r + dis;
			}
			else if(dis > R+r)
			{
				mn[i][j] = ceil(dis - r - R);
				mx[i][j] = dis + r + R;
			}
			else
			{
				mn[i][j] = 0;
				mx[i][j] = dis + r + R;
			}
		}
	}
	for(int i = 0; i < SIZE; ++i)
	{
		cir[i] = 0;
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = i+1; j < n; ++j)
		{
			if(mn[i][j] < SIZE) cir[mn[i][j]] += 1;
			if(mx[i][j]+1 < SIZE) cir[mx[i][j] + 1] -= 1;
		}
	}


	for(int i = 1; i < SIZE; ++i)
	{
		cir[i] += cir[i-1];
	}
	int k;

	for(int i = 0; i < q; ++i)
	{
		// cin >> k;
		// cout << cir[k] << endl;
		scanf("%d",&k);
		printf("%lld\n",cir[k]);
	}
	return 0;
}