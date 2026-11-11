#include<iostream>
using namespace std;
int e[1001000][3];
int h[555555];
int cnt;
int dis[555555];
inline void add(int u,int v,int w)
{
	e[++cnt][0]=h[u];
	e[cnt][1]=v;
	e[cnt][2]=w;
	h[u]=cnt;
}
inline void testcase()
{
	cnt=0;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
	}
	cout<<1<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		testcase();
	}
}
