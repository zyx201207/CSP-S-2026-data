#include<bits/stdc++.h>
using namespace std;
int m,n,a[500010],b[500010],c[500010];
bool bj=false;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	b[0]=0,c[0]=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+i-1;
	}
	if(n==0||n==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<n;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			if(m<b[i])
			{
				cout<<i-1;
				bj=true;
				break;
			}
			else if(m==b[i])
			{
				cout<<i;
				bj=true;
				break;
			}
		}
		if(bj==false)
		{
			cout<<n;
		}
	}
}
