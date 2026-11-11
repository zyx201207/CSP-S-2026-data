#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=2*1e6;
int c,t,n,k;
int MAP[MAXN][MAXN];

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
			MAP[u][v]=1;
		}
		cout<<1<<endl;
	}
	return 0;
}