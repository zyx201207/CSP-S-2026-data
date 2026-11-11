#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
int n,m,a[500005],z[500005],t[500005],top,li[500005],ca[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]]==1)
			{
				for(int k=li[a[j]]+1;k<=top;k++)
				{
					t[z[k]]=0;
				}
				top=li[a[j]];
			}
			else
			{
				t[a[j]]=1;
				z[++top]=a[j];
				li[a[j]]=top;
			}
		}
		for(int j=1;j<=500000;j++)
		{
			if(j<=top)
			{
				ca[z[j]]++;
			}
			t[j]=0;
		}
		top=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ca[i]<<" ";
	}
	return 0;
}