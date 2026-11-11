/*
考号：SN-S00463
姓名：魏熙朝
学校：西安铁一中滨河高级中学
*/ 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
int c,t,n,d,a[maxn],minn,cnt,ans,rjq;
void dfs(int now,int ed,int cost)
{
	//cout<<now<<" "<<ed<<endl;
	if(now==ed)
	{
		if(minn>cost)
		{
			minn=cost;
			cnt=1;
			return;
		}
		if(minn==cost)
		{
			cnt++;
			return;
		}
		return;
	}
	if(a[now+1]>a[now]+d)
	{
		rjq=1;
		return;
	}
	for(int i=ed;i>=now;i--)
	{
		if(a[i]>a[now]+d)continue;
		if(cost+1>minn)break;
		dfs(i,ed,cost+1);
		if(rjq==1)return;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				minn=1e18,cnt=0,rjq=0;
				dfs(i,j,0);
				//cout<<i<<" "<<j<<" "<<minn<<" "<<cnt<<endl;
				if(cnt==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}

