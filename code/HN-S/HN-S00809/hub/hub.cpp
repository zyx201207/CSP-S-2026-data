#include<bits/stdc++.h>
using namespace std;
#define int long long 

inline int read()
{
	int x(0);
	char ch(getchar());
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

namespace baoli
{

const int N=1e6+5;
int n,k,p,q,maxi,f[N],dn[N],dep[N],L[N],R[N],full[N],fat[N];
vector<int>nbr[N],pth;
bool vis[N],flag;

void dfs(int cur,int fa,int w)
{
	dn[cur]=-1,f[cur]=0;
	full[cur]=vis[cur];
	for(int nxt:nbr[cur])
	{
		if(nxt==fa)
			continue;
		dfs(nxt,cur,w);
		if(full[nxt]==true)
			continue;
		else
			full[cur]=false;
		dn[cur]=max(dn[cur],dn[nxt]);
		f[cur]+=f[nxt];
	}
	dn[cur]++;
	if(dn[cur]>=w)
		f[cur]++;
	vis[cur]=true;
	return ;
}

void go(int cur,int fa,int now)
{
	vis[cur]=true;
	if(now==0)
		return ;
	for(int nxt:nbr[cur])
		if(nxt!=fa)
			go(nxt,cur,now-1);
	return ;
}

inline bool check(int w)
{
	int ans=k+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j||dep[i]<dep[j])
				continue;
			for(int k=1;k<=n;k++)
				vis[k]=f[k]=0;
			dfs(i,fat[i],w);
			// if(i==4&&j==2)
			// {
			// 	cerr<<i<<" "<<fat[i]<<"\n";
			// for(int k=1;k<=n;k++)
			// cerr<<f[k]<<" ";cerr<<'\n';
			// }
			int cur=max(f[i],1ll);
			go(i,0,w);
			dfs(j,fat[j],w);
			go(j,0,w);
			bool flag=false;
			for(int k=1;k<=n;k++)
				if(vis[k]==false)
				{
					flag=true;
					break;
				}
			// if(i==4&&j==2)
			// {
			// 	cerr<<cur<<" "<<f[j]<<" "<<flag<<"\n";
			// }
			if(flag==false)
			{
				// int tmp=cur+(full[j]?0:max(f[j],1ll));
				// if(w==1&&tmp<=k)
				// 	cerr<<cur<<'\n';
				// if(full[j]==false)
					cur+=max(f[j],1ll);
				// if(w==1&&cur<=k)
				// {
				// 	cerr<<i<<" "<<j<<" "<<full[j]<<"\n";
				// 	cerr<<cur<<" "<<f[j]<<"\n";
				// }
					ans=min(ans,cur);
			}
		}
	return ans<=k;
}

void init(int cur,int fa)
{
	dep[cur]=dep[fa]+1;
	fat[cur]=fa;
	for(int nxt:nbr[cur])
		if(nxt!=fa)
			init(nxt,cur);
	return ;
}

inline void Work()
{
	n=read(),k=read();
	if(k==n)
	{
		cout<<"0\n";
		return ;
	}
	for(int i=0;i<=n+1;i++)
		nbr[i].clear(),vis[i]=0;
	pth.clear(),flag=false;
	for(int i=1;i<n;i++)
	{
		int x(read()),y(read());
		nbr[x].push_back(y);
		nbr[y].push_back(x);
	}
	init(1,0);
	// cerr<<check(1)<<"\n";
	int lt=-1,rt=n+1;
	while(lt+1<rt)
	{
		int mid=(lt+rt)>>1;
		if(check(mid)==true)
			rt=mid;
		else
			lt=mid;
	}
	cout<<rt<<"\n";
	return ;
}

signed main(int T)
{
	// freopen("hub.in","r",stdin);
	// freopen("std.out","w",stdout);
	// int c(read()),T(read());
	while(T--)
		Work();
	return 0;
}

}

const int N=1e6+5;
int n,k,p,q,maxi,f[N],dep[N],clen[N],L[N],R[N];
vector<int>nbr[N],pth;
bool vis[N],flag;

void dfs(int cur,int fa,int w)
{
	dep[cur]=-1,f[cur]=0;
	for(int nxt:nbr[cur])
	{
		if(nxt==fa)
			continue;
		dfs(nxt,cur,w);
		dep[cur]=max(dep[cur],dep[nxt]);
		f[cur]+=f[nxt];
	}
	dep[cur]++;
	if(dep[cur]>=w)
		f[cur]++;
	return ;
}

inline bool check(int w)
{
	// cerr<<"now "<<w<<" qwq \n";
	for(int i=0;i<pth.size();i++)
		L[i]=R[i]=k+1;
	dfs(q,0,w);
	int ps=0,ans=k+1;
	for(int i=0;i<pth.size();i++)
	{
		while(ps+1<pth.size()&&ps+1-i+clen[ps+1]<=w)
			ps++;
		if(f[pth[i]]==0)
			f[pth[i]]=1;
		L[ps]=min(L[ps],f[pth[i]]);
		if(ps+1==pth.size())
			ans=min(ans,f[pth[i]]);
	}
	// cerr<<"now "<<w<<" AwA \n";
	// cerr<<p<<"\n";
	dfs(p,0,w);
	// cerr<<"now "<<w<<" ?wA \n";
	ps=(int)(pth.size())-1;
	for(int i=(int)(pth.size())-1;i>=0;i--)
	{
		while(ps-1>=0&&i-ps+1+clen[ps-1]<=w)
			ps--;
		if(f[pth[i]]==0)
			f[pth[i]]=1;
		// cerr<<pth[i]<<" ps: "<<ps<<" val: "<<f[pth[i]]<<"\n";
		R[ps]=min(R[ps],f[pth[i]]);
		if(ps==0)
			ans=min(ans,f[pth[i]]);
	}
	for(int i=0;i<pth.size();i++)
	{
		if(i+1<pth.size())
			L[i]=min(L[i],L[i+1]);
		if(i>0)
			R[i]=min(R[i],R[i-1]);
	}
	// cerr<<"now "<<w<<" TwT \n";
	for(int i=0;i+1<pth.size();i++)
	{
		// cerr<<pth[i]<<": "<<L[i]<<" and "<<R[i+1]<<"\n";
		ans=min(ans,L[i]+R[i+1]);
	}
	return ans<=k;
}

void getlen(int cur,int fa,int len)
{
	if(len>maxi)
	{
		maxi=len;
		if(flag==false)
			p=cur;
	}
	for(int nxt:nbr[cur])
		if(nxt!=fa&&vis[nxt]==false)
			getlen(nxt,cur,len+1);
	return ;
}

bool init(int cur,int fa)
{
	if(cur==p)
	{
		pth.push_back(cur);
		return true;
	}
	for(int nxt:nbr[cur])
		if(nxt!=fa&&init(nxt,cur)==true)
		{
			pth.push_back(cur);
			return true;
		}
	return false;
}

inline void Work()
{
	n=read(),k=read();
	if(k==n)
	{
		cout<<"0\n";
		return ;
	}
	// cerr<<n<<" "<<k<<"\n";
	for(int i=0;i<=n+1;i++)
		nbr[i].clear(),vis[i]=clen[i]=0;
	pth.clear(),flag=false;
	for(int i=1;i<n;i++)
	{
		int x(read()),y(read());
		nbr[x].push_back(y);
		nbr[y].push_back(x);
	}
	getlen(1,0,0);
	q=p,maxi=0;
	getlen(q,0,0);
	init(q,0);
	for(int x:pth)
		vis[x]=true;
	flag=true;
	for(int i=0;i<pth.size();i++)
		maxi=0,getlen(pth[i],0,0),clen[i]=maxi;
	// cerr<<check(1)<<"\n";
	int lt=-1,rt=n+1;
	while(lt+1<rt)
	{
		int mid=(lt+rt)>>1;
		if(check(mid)==true)
			rt=mid;
		else
			lt=mid;
	}
	cout<<rt<<"\n";
	return ;
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c(read()),T(read());
	if(c<=6)
		return baoli::main(T);
	while(T--)
		Work();
	return 0;
}