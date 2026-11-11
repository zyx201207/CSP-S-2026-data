#include<bits/stdc++.h>
using namespace std;
int n,m,l[500100],f[300100],s[300100],a[500100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]==a[i]) 
			{
				l[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++)
		{
			f[a[j]]=1;
			if(l[j]>0) 
			{
				j=l[j]-1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(f[j]) s[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
}
