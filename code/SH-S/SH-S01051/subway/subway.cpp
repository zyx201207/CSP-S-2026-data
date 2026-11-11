#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[505],cnt=1;
long long ans=1e18;
int fa[500005];
struct node{
	int s,e,t;
}z[5000005];
struct ch{
	int c,d;
}f[10005];
int st,en;
bool cmp(ch x,ch y)
{
	return x.c<y.c;
}
void dfs(int x,long long y)
{
//	cout<<x<<" "<<y<<endl;
	if(x==en) ans=min(ans,y);
	else	
		for(int i=1;i<=cnt;i++)
		{
//			cout<<z[i].s<<" "<<z[i].e<<endl;
			if(z[i].s==x)
			{
//				cout<<"ss"<<z[i].s<<" "<<z[i].e<<endl;
				dfs(z[i].e,y+z[i].t);
			}
		}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int vt;
		cin>>vt;
//		cout<<"vt:"<<vt<<endl;
		for(int j=1;j<=vt;j++) 
		{
			cin>>f[j].c>>f[j].d;
		}
		sort(f+1,f+vt+1,cmp);
		int x=f[1].c,y=f[1].d;
		for(int j=2;j<=vt;j++)
		{
			z[cnt].s=x;
			z[cnt].e=f[j].c;
			z[cnt++].t=(y+f[j].d);
//			cout<<z[cnt-1].s<<" "<<z[cnt-1].e<<z[cnt-1].t<<" "<<endl;
			x=f[j].c,y=f[j].d;
		}
	}
	cnt--;
	for(int r=1;r<=q;r++)
	{
		cin>>st>>en;
		dfs(st,0);
		cout<<ans+a[st]+a[en];
		ans=1e18;
	}
	return 0;
}
