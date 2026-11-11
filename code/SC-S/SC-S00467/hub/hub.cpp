#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,pre[N],ans,nod[N],top,d[N],f[N];
vector<int> e[N];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int dis[N],len[N];
bool fbd[N];
int bfs(int u)
{
	queue<int> q;
	for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
	dis[u]=0;
	q.push(u);
	int las=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		las=u;
		for(auto v:e[u])
		{
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				pre[v]=u;
				q.push(v);
			}
		}
	}
	return las;
}
void dfs(int u,int fa)
{
	len[u]=0;
	for(auto v:e[u])
	{
		if(fbd[v]||v==fa) continue;
		dfs(v,u);
		len[u]=max(len[u],len[v]+1);
	}
}
void solve1(int s,int t=0)
{
	if(!t) dfs(s,0);
	else
	{
		dfs(s,t);
		dfs(t,s);
	}
	sort(len+1,len+n+1);
	ans=min(ans,len[n-k]+1);
}
int calc(int u,int mid)
{
	int res=(len[u]>=mid);
	for(auto v:e[u])
	{
		if(len[v]>=len[u]) continue;
		res+=calc(v,mid);
	}
	return res;
}
bool check_odd(int mid)
{
	int mx=1,x=1,y=top,p=top/2,mn=top;
	if(d[p+1]>=mid) return false;
	for(int i=p;i>=1;i--)
	{
		if(max(mx,i+d[i]-mid)<=i-1) mx=max(mx,i+d[i]-mid);
		else{x=i;break;}
	}
	for(int i=p+2;i<=top;i++)
	{
		if(min(mn,mid+i-d[i])>=i+1) mn=min(mn,mid+i-d[i]);
		else {y=i;break;}
	}
	bool fl=0;
	if(p+1+d[p+1]-mid<=p+1) fl|=(calc(nod[max(x,p+1+d[p+1]-mid)],mid)+calc(nod[y],mid)<=k);
	if(p+1-d[p+1]+mid>=p+1) fl|=(calc(nod[x],mid)+calc(nod[min(y,p+1-d[p+1]+mid)],mid)<=k);
	return fl;
}
void solve_odd(int rt)
{
	dfs(rt,0);
	for(int i=1;i<=top;i++) fbd[nod[i]]=1;
	for(int i=1;i<=top;i++)
	{
		int u=nod[i];
		d[i]=0;
		for(auto v:e[u]) if(!fbd[v]) d[i]=max(d[i],len[v]+1);
	}
	for(int i=1;i<=top;i++) fbd[nod[i]]=0;
	
	int l=0,r=n,res=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check_odd(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	ans=min(ans,res);
}
bool check_even(int mid)
{
	int mx=1,x=1,y=top,p=top/2,mn=top;
	for(int i=p;i>=1;i--)
	{
		if(max(mx,i+d[i]-mid)<=i-1) mx=max(mx,i+d[i]-mid);
		else{x=i;break;}
	}
	for(int i=p+1;i<=top;i++)
	{
		if(min(mn,mid+i-d[i])>=i+1) mn=min(mn,mid+i-d[i]);
		else {y=i;break;}
	}
	return calc(nod[x],mid)+calc(nod[y],mid)<=k;
}
void solve_even(int s,int t)
{
	dfs(s,t);
	dfs(t,s);
	for(int i=1;i<=top;i++) fbd[nod[i]]=1;
	for(int i=1;i<=top;i++)
	{
		int u=nod[i];
		d[i]=0;
		for(auto v:e[u]) if(!fbd[v]) d[i]=max(d[i],len[v]+1);
	}
	for(int i=1;i<=top;i++) fbd[nod[i]]=0;
	
	int l=0,r=n,res=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check_even(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	ans=min(ans,res);
}
bool check(int S)
{
	int res=0;
	for(int u=1;u<=n;u++)
	{
		for(auto v:e[u])
		{
			if(u>=v) continue;
			if((S&f[u-1])&&(S&f[v-1])) res++;
		}
	}
	return res>=k-2;
}
int calc(int S)
{
	for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
	queue<int> q;
	for(int i=1;i<=n;i++) if(S&f[i-1]) dis[i]=0,q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:e[u])
		{
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++) res=max(res,dis[i]);
	return res;
}
void solve()
{
	ans=1e9;
	n=read(),k=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n==k) return printf("0\n"),void();
	if(n<=10)
	{
		f[0]=1;
		for(int i=1;i<=n;i++) f[i]=f[i-1]*2;
		int ans=n;
		for(int i=0;i<f[n];i++)
		{
			if(__builtin_popcount(i)!=k) continue;
			if(!check(i)) continue;
			ans=min(ans,calc(i));
		}
		printf("%d\n",ans);
		return;
	}
	int s=bfs(1);
	int t=bfs(s),ds=dis[t];
	top=0;
	while(t!=s)
	{
		nod[++top]=t;
		t=pre[t];
	}
	nod[++top]=s;
//	for(int i=1;i<=top;i++) cout<<nod[i]<<" ";
//	cout<<endl;
	if(ds%2==0)
	{
		int rt=nod[(top+1)/2];
		solve1(rt);
		solve_odd(rt);
	}
	else
	{
		int rt1=nod[top/2+1],rt2=nod[top/2];
		solve1(rt1,rt2);
		solve_even(rt1,rt2);
	}
	printf("%d\n",ans);
}
void clear()
{
	for(int i=1;i<=n;i++) e[i].clear(),len[i]=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C=read(),T=read();
	while(T--) solve(),clear();
	return 0;
}
