#include<bits/stdc++.h>
using namespace std;
int m,n;
unsigned int a[200005],ma,t[2000005],mat;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		ma=max(a[i],a[i-1]);
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i]==ma)
		{
			a[i]=0;
			break;
		}
	}
	mat=ma;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			t[j]=ma&a[j];
			mat=max(t[j],t[j-1]);
		}
		ma=mat;
		for(int j=1;j<=n;j++)
		{
			if(t[i]==ma)
			{
				a[i]=0;
				break;
			}
		}
	}
	cout<<ma;
	return 0;
}
