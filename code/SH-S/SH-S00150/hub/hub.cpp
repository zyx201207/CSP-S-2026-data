#include<bits/stdc++.h>
using namespace std;
#define N 1000006
int n,k,que[N],fa[N],ql,qr,ht[2];
vector<int> edge[N];
void bfs(int wh,int fi)
{
	ql=1,qr=1;
	que[qr]=fi,fa[fi]=0,++qr;
	while(qr!=n+1)
	{
		int u=que[ql];
		++ql;
		for(int v:edge[u]) if(v!=fa[u]) que[qr]=v,fa[v]=u,++qr;
	}
	ht[wh]=que[n];
}
int ml[N];
void getml(int u,int fa)
{
	for(int v:edge[u]) if(v!=fa)
	{
		getml(v,u);
		ml[u]=max(ml[u],ml[v]+1);
	}
}
int id[N],mnr[N],mxl[N],len;
bool check(int dis)
{
	int cc=0;
	for(int i=1;i<=len;++i) if(ml[id[i]]>dis) cc+=ml[id[i]]-dis;
	if(cc>k) return 0;
	for(int i=1;i<=len;++i) mxl[i]=max(mxl[i-1],i-(dis-min(dis,ml[id[i]])));
	mnr[len+1]=1e9;
	for(int i=len;i;--i) mnr[i]=min(mnr[i+1],i+dis-min(dis,ml[id[i]]));
//	cout<<'\n'<<dis<<'\n';
//	for(int i=1;i<=len;++i) cout<<mxl[i]<<' '<<mnr[i]<<'\n';
	int l=1,r=len;
	while(l!=r)
	{
		int mid=l+r+1>>1,ll=max(1,mxl[mid]-dis),rl=max(1,len-dis-mnr[mid+1]+1);
		if(ll+rl<=k-cc) return 1;
		if(ll>rl) r=mid-1;
		else l=mid; 
	}
	return max(1,mxl[l]-dis)+max(1,len-dis-mnr[l+1]+1)<=k-cc;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		int u,v;
		for(int i=1;i<n;++i)
		{
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		bfs(0,1);
		bfs(1,ht[0]);
		for(int i=1;i<=n;++i) ml[i]=0;
		len=0;
		for(int i=ht[1];i;i=fa[i])
			id[++len]=i;
//		for(int i=1;i<=len;++i) cout<<id[i]<<' ';
//		cout<<'\n';
		for(int i=1;i<=len;++i)
		{
			int u=id[i];
			for(int v:edge[u]) if(v!=id[i-1]&&v!=id[i+1])
			{
				getml(v,u);
				ml[u]=max(ml[u],ml[v]+1);
			}
		}
		int l=0,r=len/2;
		while(l!=r)
		{
			int mid=l+r>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		cout<<l<<'\n';
		for(int i=1;i<=n;++i) edge[i].clear();
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
