#include<bits/stdc++.h> 
using namespace std;

long long a[1005];
long long m, n, cnt = 0; 

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> m >> n;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> a[i]; 
		cnt += a[1];
		cnt += a[2];
    }
	cout << cnt;
	return 0;
}
