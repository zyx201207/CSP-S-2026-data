#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,t=1;
	cin >> n >> m;
	long long a[500005]={},b[500005]={};
	cin >> a[1];
	for(int i=2;i<n;i++)
	{
		cin >> a[i];
		b[a[i]-a[i-1]]+=1;
	} 
	for(int i=0;i<=n;i++)
	{
		for(;b[i]>0;b[i]--)
		{
			if(m<i)
			{
				cout << t;
				return 0;
			}
			m-=i;
			t++;
		}
	}
	cout << t;
	return 0;
}