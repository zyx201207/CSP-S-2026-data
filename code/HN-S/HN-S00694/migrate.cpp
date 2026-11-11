#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int Read(){int x=0,f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(48<=ch&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();return x*f;}
const int kN=2e6+10,kM=1e5+10,kMod=1e9+7,kInf=1e9;

struct Node
{
	int u,dis;
	bool operator<(const Node y)
	const{return dis>y.dis;}
};

struct Events{int l,r,val;};

struct SegTree{int minn,cnt,lazy;};

void Work1();
void Work2();
// void Work3();
void GetDis(int be);
int Bfs(int be);
// void PushLazy(int root);
// void Update(int root,int l,int r,int ql,int qr,int w);

vector<SegTree>seg;
int a[kN],dis[kN],cnt[kN],into[kN],n;
vector<int>edge[kN];
vector<Events>eve[kN];

signed main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=Read(),T=Read();
	while(T--)if(11<=c&&c<=12)Work2();
			  else Work1();
}

void Work1()
{
	n=Read();int d=Read();
	for(int i=1;i<=n;i++)a[i]=Read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j&&abs(a[i]-a[j])<=d)
				edge[i].push_back(j);
	int ans=0;
	for(int i=1;i<=n;i++)
		GetDis(i),ans+=Bfs(i);
	cout<<ans/2<<endl;
	for(int i=1;i<=n;i++)edge[i].clear();
}

void GetDis(int be)
{
	priority_queue<Node>q;
	for(int i=1;i<=n;i++)dis[i]=kInf;
	dis[be]=0;q.push({be,dis[be]});
	while(q.size())
	{
		int u=q.top().u,w=q.top().dis;
		q.pop();
		for(int v:edge[u])
			if(dis[v]>dis[u]+1&&dis[u]+1<=2)
				dis[v]=dis[u]+1,q.push({v,dis[v]});
	}
}


int Bfs(int be)
{
	queue<int>q;
	for(int i=1;i<=n;i++)cnt[i]=into[i]=0;
	q.push(be);
	while(q.size())
	{
		int u=q.front();q.pop();
		if(cnt[u])continue;cnt[u]=1;
		for(int v:edge[u])
			if(dis[v]==dis[u]+1&&!cnt[v])
				into[v]+=1,q.push(v);
	}
	for(int i=1;i<=n;i++)cnt[i]=0;
	cnt[be]=1;q.push(be);
	while(q.size())
	{
		int u=q.front();q.pop();
		for(int v:edge[u])
			if(dis[v]==dis[u]+1)
			{
				cnt[v]+=cnt[u];
				if(--into[v]==0)q.push(v);
			}
	}
	int res=0;
	for(int i=1;i<=n;i++)
		if(cnt[i]==2)res++;
	return res;
}

void Work2()
{
	n=Read();int d=Read();
	for(int i=1;i<=n;i++)a[i]=Read();
	int k=d/(a[2]-a[1]);
	if(k<=1)cout<<0<<endl;
	else cout<<n-2*k+1<<endl;
}

// void Work3()
// {
// 	n=Read();int d=Read();
// 	for(int i=1;i<=n;i++)a[i]=Read();
// 	int l=1,r=1,lstr=1,flag=false;
// 	for(int i=1;i<=n;i++)
// 	{
// 		while(l<i&&abs(a[i]-a[l])>d)l++;
// 		while(r<n&&abs(a[r+1]-a[i])<=d)r++;
// 		if(!flag&&l==1&&r==n){flag=true;continue;}
// 		if(l<=i-1&&lstr+1<=r)
// 			eve[l].push_back({i+1,r,1}),
// 			eve[i].push_back({i+1,r,-1}),
// 			cerr<<l<<" "<<i<<" "<<lstr<<" "<<r<<endl;
// 		lstr=r;
// 		cout<<l<<" "<<r<<endl;
// 	}
// 	int ans=0;
// 	seg.resize(4*n+10);
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=0;j<eve[i].size();j++)
// 			Update(1,1,n,eve[i][j].l,eve[i][j].r,eve[i][j].val);
// 		if(seg[1].minn==1)ans+=seg[1].cnt;
// 	}
// 	cout<<ans<<endl;
// }

// void Update(int root,int l,int r,int ql,int qr,int w)
// {
// 	if(ql<=l&&r<=qr)
// 	{
// 		seg[root].minn+=w;
// 		seg[root].lazy+=w;
// 		return;
// 	}
// 	int mid=l+r>>1;PushLazy(root);
// 	if(ql<=mid)Update(root*2,l,mid,ql,qr,w);
// 	if(qr>mid)Update(root*2+1,mid+1,r,ql,qr,w);
// 	seg[root].cnt=0;
// 	seg[root].minn=min(seg[root*2].minn,seg[root*2+1].minn);
// 	if(seg[root*2].minn==seg[root].minn)seg[root].cnt+=seg[root*2].cnt;
// 	if(seg[root*2+1].minn==seg[root].minn)seg[root].cnt+=seg[root*2+1].cnt;
// }

// void PushLazy(int root)
// {
// 	if(seg[root].lazy)
// 	{
// 		seg[root*2].lazy+=seg[root].lazy;
// 		seg[root*2+1].lazy+=seg[root].lazy;
// 		seg[root*2].minn+=seg[root].lazy;
// 		seg[root*2+1].minn+=seg[root].lazy;
// 		seg[root].lazy=0;
// 	}
// }