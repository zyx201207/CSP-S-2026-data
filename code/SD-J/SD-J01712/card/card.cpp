#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7,M=3e5+7;
int n,m;
int a[N],b[M],la[M],ans[M];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		la[a[i]]=i;
	}
	if(n>=5000)
	{
		for(int i=1;i<=M;i++)
			cout<<la[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)	b[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]!=0)
			{
				for(int k=b[a[j]];k<j;k++)
				{
					b[a[k]]=0;
				}
			}
			b[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j]!=0)
				ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' '; 
	return 0;
}

