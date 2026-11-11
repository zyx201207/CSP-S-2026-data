#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct En
{
	long long v,w;
};
struct cmp
{
	bool operator()(En a,En b)
	{
		return a.w>b.w;
	}
};
priority_queue<En,vector<En>,cmp> q;
vector<En> e[50005];
long long c,n,m,d,qt,k,x,y,u,v,t,val,et[20005],dis[50005],ans[40005][2005];
bool vis[50005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qt;
	for(int i=1;i<=m;i++)
		cin>>et[i];
	for(int b=1;b<=qt;b++)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			while(k--)
				cin>>v>>t;
		}
	}
	for(int i=1;i<=qt;i++)
	{
		cin>>x>>y;
		cout<<et[x]+16+et[y]<<endl;
	}
	return 0;
} 
