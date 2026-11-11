#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int k=0;
	bool f=true;
	cin>>n>>m;
	int b[m+5]={0};
	int c[n+5]={0};
	int a[n+5]={0};
	cin>>a[1];
	k=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(k>a[i]) f=false;
	}
	if(f)
	{
		for(int i=1;i<=n;i++)
		{
			if(b[a[i]]==0) b[a[i]]+=i;
			else b[a[i]]=i;
			c[i]=a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cout<<b[i]<<' ';
		}
	}
	return 0;
}
