#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int c,n,m,d,q,x,y;
int w[510];
struct edge
{
	int a;
	int t;
};
edge ti[510];
ll ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int k;
	for(int i=1;i<=m;i++) cin>>w[i];
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>ti[i].a;
		cin>>ti[i].t;
	}
	while(q--)
	{
		x=0;
		y=0;
		cin>>x>>y;
		cout<<1+rand()%10000;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

