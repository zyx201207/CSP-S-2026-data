#include<bits/stdc++.h>
using namespace std;
int n,k,bui[128],book[128],ans;
vector<int>edge[128];
void flood(int u)
{
	for(int v:edge[u])
	{
		if(book[v]) continue;
		book[v]=1;
		flood(v);
	}
}
bool judge()
{
	int cnt=0;
	memset(book,0,sizeof(book));
	for(int i=1;i<=n;i++)
		if(bui[i]&&book[i]==0)
		{
			book[i]=1;
			cnt++;
			if(cnt>2)
				return false;
			flood(i);
		}
	return true;
}
int solve(int x)
{
	memset(book,0,sizeof(book));
	queue<pair<int,int> >q;
	q.push(make_pair(x,0));
	book[x]=1;
	while(!q.empty())
	{
		pair<int,int>tmp=q.front();
		int u=tmp.first,st=tmp.second;
		q.pop();
		if(bui[u])
			return st;
		for(int v:edge[u])
		{
			if(book[v]) continue;
			book[v]=1;
			q.push(make_pair(v,st+1));
		}
	}
	return INT_MAX;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ans=INT_MAX;
		memset(bui,0,sizeof(bui));
		cin>>n>>k;
		for(int i=1;i<n;i++)
			edge[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		int tot,tmp;
		for(int i=1;i<(1<<n);i++)
		{
			memset(bui,0,sizeof(bui));
			tot=0;tmp=0;
			for(int j=1;j<=i;j*=2)
				if(i&j)
				{
					bui[j]=1;
					tmp++;
				}
			if(!judge()||tmp!=k)
				continue;
			for(int j=1;j<=n;j++)
				tot=max(tot,solve(j));
			ans=min(tot,ans);
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
By luogu 737194
I was born to break the game
When the Gods play with moral flame
Now I rewrite the rules in my name
From nothingness , I rise again
This is the final masquerate
Where the faith and freedom were remade
I sold the truth that I never laid
To buy the dawn that never fade
      ----<<Gambit of the Gods>> 
*/
