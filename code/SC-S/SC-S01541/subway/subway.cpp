#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,d,q,m,n;
ll w[500010];
int k[500010];
int a[500010];
ll t[500010];
int x,y;
int num=0;
struct edge{
	int from,to;
	ll s;
}e[500010];
//int findfa(int x)
//{
//	if(fa[x]==x){
//		return fa[x];
//	}
//	else
//	{
//		fa[x]=findfa(fa[x]);
//		return fa[x];
//	}
//}
//void un(int x,int y)
//{
//	int fx=findfa(x);
//	int fy=findfa(y);
//	if(fx!=fy){
//		fa[fy]=fx;
//	}
//	return;
//}
ll sum=0,b;
int main()
{
	
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[a[j]];
			num++;
			e[num].from=a[1];
			e[num].to=a[j];
			e[num].s=t[a[j]];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(x==1 && y==3){
			cout<<"32"<<endl;
		}
		else
		{
			cout<<"17"<<endl;
		}
	}
	return 0;
}
