#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],t[500010],cnt=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i-1])
		{
			cout<<i-1<<' ';
		}
	}
	cout<<m;
	return 0;
}
