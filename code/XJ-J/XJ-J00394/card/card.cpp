#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n,a[200010],t[20010]; 
bool f=0;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]++;
		if(t[a[i]]>=1)
		{
			f=1;
		}
	}
	for(int i=n-f;i>=1;i++)
	{
		cout<<i<<" ";
	}
	return 0;
}