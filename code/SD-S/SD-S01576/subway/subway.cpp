#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int c,n,m,d,q;
int w[maxn],a[maxn][510],t[510];
long long s=0;
void sou(int x,int y)
{
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[j];
		}
	}
	sou(1,1);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		s+=w[x]+t[x]+w[y]+t[y];
		cout<<s;
	}
	return 0;
}
