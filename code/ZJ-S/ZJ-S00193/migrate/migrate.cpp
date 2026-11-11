#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],ms[5005];
int n,d,l,r;
int cnt;
int cntx[5005];
void dfs(int x,int stp)
{
	if(stp==ms[x])cntx[x]++;
	if(stp>ms[x])return;
	for(int i=x+1;i<=n;i++)
	{
		int sum=a[i]-a[x];
		if(sum>d)
		{
			break;
		}
		else
		{
			dfs(x+1,stp+1);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int i;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(l=1;l<=n;l++)
		{
			memset(cntx,0,sizeof(cntx));
			for(i=1;i<=n;i++)
			{
				ms[i]=0;
			}
			int lst=l;
			int sum=0;
			ms[l-1]=1;
			for(i=l;i<=n;i++)
			{
				sum=a[i]-a[lst];
				if(sum>d)
				{
					if(a[i]-a[i-1]>d)
					{
						break;
					}
					ms[i]++;
					lst=i;
				}
				ms[i]+=ms[i-1];
			}
			dfs(l,0);
			for(i=l;i<=n;i++)
			{
				if(cntx[i]==2)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*

*/