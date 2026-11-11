#include<bits/stdc++.h>
typedef int int32;
#define int long long
using namespace std;
/*
作者: HN-S00892 wbw_121124(luogu uid 792595)
17:08 开始写暴力

不可以 不可以总司令
*/
const int N = 2e6 + 5;
int c,t,n,d,a[N],dis[N],ans,vis[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			dis[i]=0;
			vector<int>q;
			q.push_back(i);
			vis[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				while(!q.empty()&&a[q[0]]+d<a[j])
					q.erase(q.begin());
				if(q.empty())
					break;
				dis[j]=dis[q[0]]+1;
				if(q.size()==1)
					vis[j]=vis[q[0]]?vis[q[0]]==1?1:3:0;
				else if(!vis[q[0]])
					vis[j]=0;
				else if(dis[q[0]]==dis[q[1]]&&!vis[q[1]])
					vis[j]=0;
				else if(q.size()>2&&dis[q[0]]==dis[q[1]]
					&&dis[q[0]]==dis[q[2]])
					vis[j]=0;
				else if(dis[q[0]]==dis[q[1]])
					vis[j]=vis[q[0]]==1&&vis[q[0]]==1?2:0;
				else
					vis[j]=vis[q[0]]?vis[q[0]]==1?1:3:0;
				ans+=vis[j]>=2;
				q.push_back(j);
				// cerr<<'#'<<i<<','<<j<<':'<<vis[j]<<' '<<
				// 	dis[j]<<'^'<<(dis[q[0]]==dis[q[1]])<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}