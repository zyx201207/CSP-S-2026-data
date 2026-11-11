#include<bits/stdc++.h>
using namespace std;
int n,t;
long long cnt[2000010],a[2000010],f[2000010],d;
vector<int>v[2000010];
int main()
{
	scanf("%*d%d",&t);
	while(t--)
	{
		for(int i=1;i<=n;i++) v[i].clear();
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			for(int j=1;j<i;j++)
				if(a[i]-a[j]<=d)
					v[j].push_back(i);
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) f[j]=-1,cnt[j]=0;
			queue<pair<int,int>> q;
			q.push({i,0});
			while(!q.empty())
			{
				int now=q.front().first,step=q.front().second;
				q.pop();
				if(f[now]==-1||step==f[now])
				{
					cnt[now]++;
					f[now]=step;
				}
				else continue;
				for(auto to:v[now])
					if(f[to]==-1||step+1<=f[to])
						q.push({to,step+1});
			}
			for(int j=1;j<=n;j++)
				if(cnt[j]==2)
					ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//俄顷打开O2跑，MLE漠漠向昏黑。Dijk多年TLE，记搜依旧会RE。自经OI多WA，freopen何由彻！