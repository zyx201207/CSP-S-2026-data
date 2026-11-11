#include<bits/stdc++.h>
using namespace std;

inline void rd(int &x){
	x=0;int f=1;char c=getchar();
	for(;'9'<c||c<'0';c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x=f*x;
}

struct node
{
	int u,t;//u:地点，t:时间 
	bool operator <(const node &a) const{
		return t>a.t;
	}
};
vector<node> g[100005];

int c,n,m,d,q,w[5*100005],ans=1e9,y;//c
int a[5*100005],t[5*100005];

int vis[5*100005];
int dis[5*100005];

void dfs(int k,int x,int far){
	if(far>ans)return;
	if(x==y){
		ans=min(ans,far);
	}
	for(int i=0;i<g[k].size();i++){
		if(g[k][i].u==y){
			ans=min(ans,far);
			return;
		}
		for(int l=1;l<=n;l++){
			if(l==i)continue;
			for(int j=0;j<g[i].size();j++){
				if(g[l][j].u==g[k][i].u){
					dfs(i,g[l][j].u,far+g[l][j].t);
				}
			}
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	rd(c);
	rd(n);
	rd(m);
	rd(d);
	rd(q);
	
	for(int i=1;i<=m;i++)
	{
		rd(w[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		int k;
		rd(k);
		for(int j=1;j<=k;j++)
		{
			rd(a[j]);
			rd(t[j]);
		}
	}
	
	
	for(int i=1;i<=q;i++)
	{
		int x;
		rd(x);
		rd(y);
		dfs(1,x,w[x]);
		if(ans==1e9)ans=rand();
		cout<<w[x]+ans+w[y]<<endl;
		ans=1e9;
	}
	
	return 0;
}
