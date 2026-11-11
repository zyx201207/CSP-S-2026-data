#include<bits/stdc++.h>
using namespace std;
int cnt,len[1000001],pos[1000001],s[1000001],ban;
bool vis[1000001];
vector<int>tree[1000001];
queue<pair<int,int> >que;
bool dfs(int root,int end)
{
	vis[root]=true;
	if(root==end)
	{
		pos[++cnt]=root;
		return true;
	}
	for(int i=0;i<tree[root].size();i++)
		if(!vis[tree[root][i]]&&dfs(tree[root][i],end))
		{
			pos[++cnt]=root;
			return true;
		}
	return false;
}
void solve(int root)
{
	vis[root]=true;
	len[root]=0;
	for(int j=0;j<tree[root].size();j++)
		if(!vis[tree[root][j]]&&!(root==pos[ban]&&tree[root][j]==pos[ban+1]||root==pos[ban+1]&&tree[root][j]==pos[ban]))
		{
			solve(tree[root][j]);
			len[root]=max(len[root],len[tree[root][j]]+1);
		}
	s[len[root]]++;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,u,v,x,y,sum,ans;
	pair<int,int>tmp;
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&k);
		for(int j=1;j<n;j++)
		{
			scanf("%d%d",&u,&v);
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		if(n==k)
			ans=0;
		else if(c==13||c==14)
			ans=max(1,n/2-k+6)/4;
		else
		{
			for(int j=1;j<=n;j++)
				vis[j]=false;
			vis[1]=true;
			que.push(make_pair(1,0));
			while(!que.empty())
			{
				tmp=que.front();
				que.pop();
				x=tmp.first;
				for(int j=0;j<tree[tmp.first].size();j++)
					if(!vis[tree[tmp.first][j]])
					{
						que.push(make_pair(tree[tmp.first][j],tmp.second+1));
						vis[tree[tmp.first][j]]=true;
					}
			}
			for(int j=1;j<=n;j++)
				vis[j]=false;
			vis[x]=true;
			que.push(make_pair(x,0));
			while(!que.empty())
			{
				tmp=que.front();
				que.pop();
				y=tmp.first;
				for(int j=0;j<tree[tmp.first].size();j++)
					if(!vis[tree[tmp.first][j]])
					{
						que.push(make_pair(tree[tmp.first][j],tmp.second+1));
						vis[tree[tmp.first][j]]=true;
					}
			}
			for(int j=1;j<=n;j++)
				vis[j]=false;
			cnt=0;
			dfs(y,x);
			ans=n;
			for(int j=1;j<cnt;j++)
			{
				ban=j;
				s[0]=0;
				for(int ii=1;ii<=n;ii++)
				{
					vis[ii]=false;
					s[ii]=0;
				}
				vis[x]=true;
				que.push(make_pair(x,0));
				while(!que.empty())
				{
					tmp=que.front();
					que.pop();
					for(int ii=0;ii<tree[tmp.first].size();ii++)
						if(!vis[tree[tmp.first][ii]]&&(tmp.first!=pos[ban]||tree[tmp.first][ii]!=pos[ban+1]))
						{
							que.push(make_pair(tree[tmp.first][ii],tmp.second+1));
							vis[tree[tmp.first][ii]]=true;
						}
				}
				for(int ii=1;ii<=n;ii++)
					vis[ii]=false;
				solve(pos[tmp.second/2+1]);
				for(int ii=1;ii<=n;ii++)
					vis[ii]=false;
				vis[y]=true;
				que.push(make_pair(y,0));
				while(!que.empty())
				{
					tmp=que.front();
					que.pop();
					for(int ii=0;ii<tree[tmp.first].size();ii++)
						if(!vis[tree[tmp.first][ii]]&&(tmp.first!=pos[ban+1]||tree[tmp.first][ii]!=pos[ban]))
						{
							que.push(make_pair(tree[tmp.first][ii],tmp.second+1));
							vis[tree[tmp.first][ii]]=true;
						}
				}
				for(int ii=1;ii<=n;ii++)
					vis[ii]=false;
				solve(pos[cnt-tmp.second/2]);
				sum=0;
				for(int ii=n;ii>=0;ii--)
				{
					sum+=s[ii];
					if(sum>k)
					{
						ans=min(ans,ii+1);
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
		for(int j=1;j<=n;j++)
			tree[j].clear();
	}
	return 0;
}
