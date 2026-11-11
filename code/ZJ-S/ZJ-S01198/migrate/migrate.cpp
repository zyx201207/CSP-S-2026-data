#include<bits/stdc++.h>
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
using namespace std;
const int N=2e6+5;
int CST,CSN;
int n,f[5010];
long long d,x[N],g[5010];
struct SegTree
{
	struct Node{int mn;long long cnt;}tr[5010<<2];
	void pushup(int id)
	{
		int lc=ls(id),rc=rs(id);
		if(tr[lc].mn==tr[rc].mn) tr[id].cnt=tr[lc].cnt+tr[rc].cnt;
		else if(tr[lc].mn<tr[rc].mn) tr[id].cnt=tr[lc].cnt;
		else tr[id].cnt=tr[rc].cnt;
		tr[id].mn=min(tr[lc].mn,tr[rc].mn);
	}
	void upt(int id,int l,int r,int p,int v,long long k)
	{
		if(l==r){tr[id].mn=v,tr[id].cnt=k;return;}
		int mid=l+r>>1;
		if(mid>=p) upt(ls(id),l,mid,p,v,k);
		else upt(rs(id),mid+1,r,p,v,k);
		pushup(id);
	}
	pair<int,long long> qry(int id,int l,int r,int x,int y)
	{
		if(x<=l&&r<=y) return make_pair(tr[id].mn,tr[id].cnt);
		int mid=l+r>>1;pair<int,long long> res;res.first=-1;
		if(mid>=x) res=qry(ls(id),l,mid,x,y);
		if(mid<y)
		{
			if(res.first==-1) res=qry(rs(id),mid+1,r,x,y);
			else
			{
				pair<int,long long> tmp=qry(rs(id),mid+1,r,x,y);
				if(res.first==tmp.first) res.second+=tmp.second;
				else if(tmp.first<res.first) res=tmp;
			}
		}
		return res;
	}
}T;
inline bool check(int s,int t)
{
	for(int i=s;i<=t;i++) f[i]=N,g[i]=0;
	f[s]=0,g[s]=1;
	for(int i=s;i<=t;i++) T.upt(1,s,t,i,f[i],g[i]); 
	for(int i=s+1,j=s;i<=t;i++)
	{
		while(j<=i&&x[i]-x[j]>d) j++;
		if(i==j) return false;
		pair<int,long long> tmp=T.qry(1,s,t,j,i-1);
		f[i]=tmp.first+1,g[i]=tmp.second;
		T.upt(1,s,t,i,f[i],g[i]); 
	}
//	for(int i=s;i<=t;i++) cout<<'#'<<i<<' '<<f[i]<<' '<<g[i]<<'\n';
//	cout<<"end.\n";return false;
	bool ok=(g[t]==2);
	for(int i=s;i<=t;i++) T.upt(1,s,t,i,N,0);
//	if(ok) cout<<"#("<<s<<','<<t<<")\n";
	return ok;
}
inline void Solve()
{
	cin>>n;cin>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	long long ans=0;
	for(int i=1;i<n;i++)
		for(int j=i+2;j<=n;j++)
			ans+=check(i,j);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>CST>>CSN;
	while(CSN--) Solve();
	return 0;
}
