#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,z[1000005],jl[1000005],fa[1000005];
vector<int> adj[1000005];
vector<int> son;
bool xz[1000005];
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
void cj(int i)
{
	for(int x:adj[i])
	{
		if(jl[x]>jl[i]+1)
		{
			jl[x]=jl[i]+1;
			cj(x);
		}
	}
}
int mj(int x,int l)
{
//	cout<<x<<" "<<l<<"  ";
//	for(int i=1;i<=x-1;i++)
//	{
//		cout<<z[i]<<" ";
//	}
//	cout<<endl;
	if(x==k+1)
	{
		if(l>=3)
		{
			return 10000000;
		}
		for(int i=1;i<=n;i++)
		{
			jl[i]=10000000;
			if(xz[i])
			{
				jl[i]=0;
			}
		}
		for(int i=1;i<=k;i++)
		{
			cj(z[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,jl[i]);
		}
		return ans;
	}
	int l1,ans=10000000;
	for(int i=z[x-1]+1;i<=n;i++)
	{
		l1=l+1;
		for(int aa:adj[i])
		{
			if(xz[aa] and find(aa)!=find(i))
			{
				son.push_back(find(aa));
				fa[find(aa)]=i;
				l1--;
			}
		}
		z[x]=i;
		xz[i]=true;
		ans=min(mj(x+1,l1),ans);
		xz[i]=false;
		for(int xxx:son)
		{
			fa[xxx]=xxx;
		}
		son.clear();
	}
	return ans;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		cout<<mj(1,0)<<endl;
		for(int i=1;i<=n;i++)
		{
			adj[i].clear();
		}
	}
	return 0;
}
