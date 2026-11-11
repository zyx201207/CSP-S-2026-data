#include<bits/stdc++.h>
using namespace std;
struct To{
	int v,l;
};
To es[100005][45];
int gt[100005];
struct Path{
	int ed;
	int len;
	int l;
	bool operator<(const Path oth)const
	{
		return len>oth.len;
	}
};
int w[100005];
int t[505][100005];
int c,n,m,d,p;
unordered_map<string,int> mp;
long long dis[100005];
priority_queue<Path> q;
void dfs(int s)
{
	for(int i=1;i<=m;i++)
	{
		dis[i]=1e17;
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i][s]!=0)
		{
			q.push({s,t[i][s]+w[s],i});
		}
	}
	while(!q.empty())
	{
		int now=q.top().ed;
		int len=q.top().len;
		int l=q.top().l;
		q.pop();
		if(len<dis[now])
		{
			dis[now]=len;
			for(int i=1;i<=gt[now];i++)
			{
				int nxt=es[now][i].v;
				int nxl=es[now][i].l;
				if(nxt==now)
				{
					continue;
				}
				if(nxl==l)
				{
					q.push({nxt,len,l});
				}
				else
				{
					q.push({nxt,len+t[l][now]+t[nxl][now],nxl});
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int lst=0;
		for(int j=1;j<=k;j++)
		{
			int x;
			cin>>x;
			cin>>t[i][x];
			if(j!=1)
			{
				es[lst][++gt[lst]]={x,i};
				es[x][++gt[x]]={lst,i};
			}
			lst=x;
		}
	}
	for(int i=1;i<=m;i++)
	{
		dfs(i);
		for(int j=1;j<=m;j++)
		{
			string s="";
			s+=to_string(i);
			s+=' ';
			s+=to_string(j);
			mp[s]=dis[j]+w[j];
		}
	}
	for(int i=1;i<=p;i++)
	{
		int x,y;
		cin>>x>>y;
		string s="";
		s+=to_string(x);
		s+=' ';
		s+=to_string(y);
		cout<<mp[s]<<endl;
	}
	/*
	0 2 5 20 2
	4 1 9 2 5
	3 1 5 2 7 4 6
	3 2 3 3 4 5 7
	1 3
	1 2
	*/
	return 0;
 } 
