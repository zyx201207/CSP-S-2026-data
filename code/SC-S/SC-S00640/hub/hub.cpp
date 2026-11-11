#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
int c,t,n,k,x,y,dep[N],rs,kl,h[N],mx[N],f[N],dis[N];
vector <int > v[N];

int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void dfs(int nw,int fa)
{
	if(kl) return ;
	dep[nw]=0;
	for(int go:v[nw]) if(go!=fa)
	{
		dfs(go,nw);
		dep[nw]=max(dep[nw],dep[go]+1);
	}
	if(dep[nw]==rs)
	{
		kl=nw;
		return ;
	}
	return ;
}

void init(int nw,int fa)
{
	mx[nw]=h[nw];
	for(int go:v[nw]) if(go!=fa)
	{
		h[go]=h[nw]+1;
		init(go,nw);
		mx[nw]=max(mx[nw],mx[go]);
	}
	if(mx[nw]<=rs) mx[nw]=-10*N;
	return ;
}

int flag=0;

void dfs2(int nw,int fa,int cm)
{
	if(cm<=rs&&mx[nw]-h[nw]<=rs) flag=1;
	multiset <int > st;
	for(int go:v[nw]) if(go!=fa) st.insert(mx[go]-h[nw]);
	for(int go:v[nw]) if(go!=fa)
	{
		st.erase(st.lower_bound(mx[go]-h[nw]));
		int cs=-10*N,kp=-10*N;
		if(!st.empty()) cs=*prev(st.end());
		if(h[nw]>rs) kp=0;
		dfs2(go,nw,max(max(cm+1,cs+1),kp+1));
		st.insert(mx[go]-h[nw]);
	}	
	return ;
} 

int check(int k)
{
	rs=k,kl=0,flag=0;
	dfs(1,0);
	if(kl==0) return 1;
	init(kl,0);
	dfs2(kl,0,-10*N);
	for(int i=1;i<=n;i++) dep[i]=h[i]=mx[i]=0;
	return flag;
}

int tag[N],vis[N],res;

void cl(int nw,int fa,int dep)
{
	dis[nw]=min(dis[nw],dep);
	for(int go:v[nw]) if(go!=fa)
	{
		cl(go,nw,dep+1);
	}
	return ;
}

void solve(int st)
{
	if(st==n+1)
	{
		int ct=0;
		for(int i=1;i<=n;i++) ct+=tag[i];
		if(ct>k) return ;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) if(tag[i]==1) f[i]=i;
		for(int i=1;i<=n;i++) if(tag[i]==1)
		{
			for(int k:v[i]) if(tag[k]) f[find(k)]=find(i);
		}
		for(int i=1;i<=n;i++) if(tag[i]==1) vis[find(i)]=1;
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=vis[i];
		if(cnt<=2)
		{
			for(int i=1;i<=n;i++) dis[i]=10*N;
			for(int i=1;i<=n;i++) if(tag[i]) 
			{
				cl(i,0,0);
			}
			int mx=0;
			for(int i=1;i<=n;i++) mx=max(mx,dis[i]);
			res=min(res,mx);
		}
		return ;
	}
	tag[st]=0,solve(st+1);
	tag[st]=1,solve(st+1);
	return ;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(k==2)
		{
			int l=1,r=n,mid=-1,res=0;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(check(mid)) res=mid,r=mid-1;
				else l=mid+1;
			}
			cout<<res<<"\n";
		}
		else if(c<=3)
		{
			res=N;
			solve(1);
			cout<<res<<"\n";
		}
		else 
		{
			int k1=k/2,k2=k-k1,m=n/2+2,res=0;
			for(int rs=1;rs<=m;rs++)
			{
				if(rs+k1+rs+rs+k2+rs>=m) 
				{
					res=rs;
					break;
				}
			}
			cout<<res<<"\n";
		}
		for(int i=1;i<=n;i++) v[i].clear();
	}
	return 0;
}