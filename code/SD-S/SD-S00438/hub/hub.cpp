#include <bits/stdc++.h>
using namespace std;
int cccc,asdfjkl;
int n,k;
vector<int> t[1000005];
int e[105];
bool flag[105];
int minn;
void dfsone(int x)
{
	flag[x]=1;
	for(int i=0;i<t[x].size();i++)
	{
		if(flag[t[x][i]])	continue;
		if(e[t[x][i]])
		{
			dfsone(t[x][i]);
		}
	 } 
	return;
}
int qiu(int x,int y)
{
	if(e[x])	return y;
	flag[x]=1;
	int minn=0x3f3f3f3f;
	for(int i=0;i<t[x].size();i++)
	{
		if(flag[t[x][i]])	continue;
		minn=min(minn,qiu(t[x][i],y+1));
	}
	return minn;
}
int check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		flag[i]=0;
		cnt+=e[i];
	}
	if(cnt!=k)	return -1;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==0&&e[i])
		{
			dfsone(i);
			cnt++;
		}
	}
	if(cnt>2)	return -1;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(e[i]==0)
		{
			for(int i=1;i<=n;i++)
			{
				flag[i]=0;
			}
			cnt=max(cnt,qiu(i,0));
		}
	}
	return cnt;
}
void dfs(int x)
{
	if(x>n)
	{
		int uo=check();
		if(uo!=-1)
		{
			minn=min(minn,uo);
		}
		return;
	}
	e[x]=1;
	dfs(x+1);
	e[x]=0;
	dfs(x+1);
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cccc>>asdfjkl;
	while(asdfjkl--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			t[i].clear();
		}
		int x,y;
		minn=0x3f3f3f3f;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			t[x].push_back(y);
			t[y].push_back(x);
		}
		dfs(1);
		cout<<minn<<'\n';
	}
	return 0;
}
