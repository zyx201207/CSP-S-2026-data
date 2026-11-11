#include<bits/stdc++.h>
using namespace std;
struct node{
	int a[10001];
	int t[10001];
	int w;
}k[10001];
long long w[10001],x[10001],y[10001];
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c=0,n=0,m=0,d=0,q=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i].w;
		for(int j=1;j<=k[i].w;j++){
			cin>>k[i].a[i]>>k[i].t[i];
		}
	}
	int ans=0;
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)
	{
		ans+=w[i]+w[y[q]]+1;
		for(int j=x[q];j<=y[q];j++)
		{
			ans+=k[i].t[i]+k[i].t[i+1]+k[i+1].t[i+1]+k[i+1].t[i+2];
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
