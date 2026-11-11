#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int aa,bb;
int  k;
int x,y;
struct node
{
	int val,op;
};
vector <node > mp[500005];
int vis[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		// sum+=w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>aa>>bb;
		}
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<rand()%m+1+w[x]+w[y]<<endl;
	}
}