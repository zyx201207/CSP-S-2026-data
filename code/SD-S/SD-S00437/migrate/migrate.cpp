#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,d,x[N];
bool vis[N];
bool check(int u,int v)
{
	queue<pair<int,int> > que;
	que.push(make_pair(u,0));
	vector<int> vec;
	while(que.size()!=0)
	{
		int now=que.front().first,t=que.front().second;
		que.pop();
		if(now==v)
		{
			vec.push_back(t);
		}
		for(int i=1;i<=n;i++)
		{
			if((vis[i]==false)&&((abs(x[now]-x[i]))<=d))
			{
				vis[i]=true;
				que.push(make_pair(i,t));
			}
		}
	}
	int cnt=0,len=vec.size(),minn=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<len;i++)
	{
		if(minn==vec[i])
		{
			cnt++;
		}
		minn=min(minn,vec[i]);
	}
	if(cnt)
	{
		return true;
	}
}
void solve_problems()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	int cnt=0;
	for(int u=1;u<=n;u++)
	{
		for(int v=u+1;v<=n;v++)
		{
			if(check(u,v))
			{
				cnt++;
			}
		}
	}
	cout<<cnt<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T=1;
	cin>>c>>T;
	for(int t=1;t<=T;t++)
	{
		solve_problems();
	}
	return 0;
}
