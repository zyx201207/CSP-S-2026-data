#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int w[500005];
struct node{
	int id,t;
};
vector<node> vec[500005];
int dp[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		for(int j=1;j<=x;j++)
		{
			node h;h.id=read();h.t=read();
			vec[h.id].push_back(node{i,h.t});
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<vec[i].size();j++)
			for(int k=0;k<vec[i].size();k++)
			{
				node x=vec[i][j],y=vec[i][k];
				dp[x.id][y.id]=min(dp[x.id][y.id],x.t+y.t);
			}
	}
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--)
	{
		int s=read(),t=read(),ans=LLONG_MAX;
		for(int i=0;i<vec[s].size();i++)
			for(int j=0;j<vec[t].size();j++)
				ans=min(ans,vec[s][i].t+vec[t][j].t+dp[vec[s][i].id][vec[t][j].id]);
		printf("%lld\n",ans+w[s]+w[t]);
	}
	return 0;
}
//fu guang lue ying,chong shan cai yun jian
//ni de fu xian,chuan yue qian bai nian
//ren shen bu guo,duan duan san wan tian
//liu lian liu lian liu lian liu lian
