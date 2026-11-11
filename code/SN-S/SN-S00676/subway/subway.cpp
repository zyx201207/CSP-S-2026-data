#include<bits/stdc++.h>
using namespace std;
const int N=500,M=500005
int C,n,m,d,q,num[M],k[N],a[N][M],t[N][M];
struct st
{
	int u,w,id;
};
vector<vector<st>> G;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>num[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=k[i];j++)
		{
			G[i].push_back({a[i][j]});
			G[a[i][j]].push_back({a[i][j-1],i,j-1});
			
		}
	}
	return 0;
}
