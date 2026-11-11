#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,c,n,k,b[300009],vis[300009],sum,re,f[19][100009],tot,dep[300009];
vector<int> e[300009],son[300009];
pair<int,int> dia[300009],pre[300009],suf[300009];
void dfs2(int x)
{
	vis[x]=1;
	for(int i:e[x])
	{
		if(vis[i]==0&&b[i])
		{
			dfs2(i);
		}	
	}
	return ;
}
int dfs3(int x,int fa)
{
	if(b[x])
	{
		return 0;
	}
	int minn=0x3f3f3f3f;
	for(int i:e[x])
	{
		if(fa==i)
		{
			continue;
		}
		minn=min(minn,dfs3(i,x)+1);
	}
	return minn;
}
void check()
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0&&b[i])
		{
			dfs2(i);
			cnt++;
			if(cnt>2)
			{
				break;
			}
		}
	}
	if(cnt>2)
	{
		return ;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			ans=max(ans,dfs3(i,i));
		}
	}
	re=min(re,ans);
	return ;
}
void dfs(int x)
{
	if(sum>k)
	{
		return ;
	}
	if(x>n)
	{
		if(sum<k)
		{
			return ;
		}
		check();
		return  ;
	}
	b[x]=1;
	sum++;
	dfs(x+1);
	b[x]=0;
	sum--;
	dfs(x+1);
	return ;
}

int lca(int x,int y)
{
	if(dep[x]<dep[y])
	{
		swap(x,y);
	}
	int del=dep[x]-dep[y];
	for(int i=18;i>=0;i--)
	{
		if((del>>i)&1)
		{
			x=f[i][x];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(int i=18;i>=0;i--)
	{
		if(f[i][x]!=f[i][y])
		{
			x=f[i][x],y=f[i][y];
		}
	}
	return f[0][x];
}
int dis(int x,int y)
{
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void checkans(pair<int,int> x,pair<int,int> y)
{
	tot=min(tot,max((dis(x.first,x.second)+1)/2,(dis(y.first,y.second)+1)/2));
	return ;
}
pair<int,int> merge(pair<int,int> x,pair<int,int> y)
{
	int tmp1=dis(x.first,x.second),tmp2=dis(x.first,y.first),tmp3=dis(x.second,y.first);
	int maxn=max(tmp1,max(tmp2,tmp3));
	if(maxn==tmp1)
	{
		
	}
	else if(maxn==tmp2)
	{
		x.second=y.first;
	}
	else
	{
		x.first=y.first;
	}
	tmp1=dis(x.first,x.second),tmp2=dis(x.first,y.second),tmp3=dis(x.second,y.second);
	maxn=max(tmp1,max(tmp2,tmp3));
	if(maxn==tmp1)
	{
		
	}
	else if(maxn==tmp2)
	{
		x.second=y.second;
	}
	else
	{
		x.first=y.second;
	}
	return x;
}
void dfsdep(int x)
{
//	cout<<x<<endl;
	dep[x]=dep[f[0][x]]+1;
	for(int i:e[x])
	{
		if(i==f[0][x])
		{
			continue;
		}
		son[x].push_back(i);
		f[0][i]=x;
		dfsdep(i);
	}
	return ;
}
void dfsdia(int x)
{
	dia[x]={x,x};
	for(int i:e[x])
	{
		if(i==f[0][x])
		{
			continue;
		}
		dfsdia(i);
		dia[x]=merge(dia[x],dia[i]);
	}
	return ;
}
void dfsans(int x,pair<int,int> fa)
{
//	cout<<x<<' '<<fa.first<<' '<<fa.second<<endl;
	if(x!=1)
	{
		checkans(dia[x],fa);
	}
	else
	{
		tot=(dis(dia[x].first,dia[x].second)+1)/2;
	}
	for(int i=0;i<son[x].size();i++)
	{
		pre[son[x][i]]=(i==0 ? dia[son[x][i]] : merge(pre[son[x][i-1]],dia[son[x][i]]));
	}
	for(int i=son[x].size()-1;i>=0;i--)
	{
		suf[son[x][i]]=(i==son[x].size()-1 ? dia[son[x][i]] : merge(suf[son[x][i+1]],dia[son[x][i]]));
	}
	for(int i=0;i<son[x].size();i++)
	{
		pair<int,int> tmp={x,x};
		if(x>1)
		{
			tmp=merge(tmp,fa);
		}
		if(i>0)
		{
			tmp=merge(tmp,pre[son[x][i-1]]);
		}
		if(i<son[x].size()-1)
		{
			tmp=merge(tmp,suf[son[x][i+1]]);
		}
		dfsans(son[x][i],tmp);
	}
	return ;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c<=6)
	{
		while(t--)
		{
			for(int i=0;i<=n+1;i++)
			{
				e[i].clear();
			}
			cin>>n>>k;
			int x=0,y=0;
			for(int i=1;i<n;i++)
			{
				cin>>x>>y;
				e[x].push_back(y),e[y].push_back(x);
			}
			re=0x3f3f3f3f;
			dfs(1);
			cout<<re<<'\n';
			re=0;
		}
		return 0;
	}
	while(t--)
	{
		for(int i=0;i<=n+1;i++)
		{
			e[i].clear(),son[i].clear(),dep[i]=0;
			for(int j=0;j<=18;j++)
			{
				f[j][i]=0;
			}
			pre[i]={0,0},suf[i]={0,0},dia[i]={0,0};
		}
		tot=0x3f3f3f3f;
		cin>>n>>k;
		int x=0,y=0;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			e[x].push_back(y),e[y].push_back(x);
		}
		dfsdep(1);
		for(int i=1;i<=18;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=f[i-1][f[i-1][j]];
			}
		}
		dfsdia(1);
		dfsans(1,{0,0});
		cout<<tot<<'\n';
	}
	return 0;
}
/*
9 1
5 2
1 2
2 3
3 4
4 5
*/
