#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);                      												
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a[n];
	for(int i = 0;i < n;i ++) cin >> a[i];
	int d[n];													
	for(int i = 0;i < n;i ++)
	{
		for(int j = 0;j < m;j ++)
		{
			d[i] = a[i] & a[i + 1];
		}
	}
	int max=0;
	for(int i = 0;i < n;i ++)
	{
		if(d[i] > max)
		{
			max = d[i];
		}
	}
	cout << max;
}
