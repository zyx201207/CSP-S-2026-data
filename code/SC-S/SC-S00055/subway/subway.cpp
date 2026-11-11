#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int w[5*N];
struct node{
	int k,t;
}a[N/10][N/10];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int l;
		cin>>l;
		for(int j=1;j<=l;j++)
		{
			cin>>a[l][j].k>>a[l][j].t;
		}
	}
	while(q--)
	{
		int s,f;
		cin>>s>>f;
		cout<<mt19937(time(0))<<"\n";
	}
	return 0;
}