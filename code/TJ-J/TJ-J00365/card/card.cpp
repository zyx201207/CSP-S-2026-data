#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int cnt[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		bool f[300005]={0};
		for(int j=i;j<=n;j++)
		{
			f[j]=1;
		}
		for(int j=1;j<=m;j++)
		{
			if(f[j]==1)
			{
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
