#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500005],k,myx,myy;
struct stu
{
	int a,t;
}e[5][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>e[i][j].a>>e[i][j].t;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(e[1][i].a==e[2][j].a)
			{
				myx=i;myy=j;
			}
		}
	}
	while(q--)
	{
		ll x,y,f=0,f1=0,f2=0,f2f=0,l=0,l1=0,l2l=0,l2=0,sum=0;
		cin>>x>>y;
		for(int i=1;i<=k;i++)
		{
			if(e[1][i].a==x)
			{
				f=1;
				f1=i;
			}
			else if(e[1][i].a==y)
			{
				l=1;
				l1=i;
			}
			else if(e[2][i].a==x)
			{
				f2f=2;
				f2=i;
			}
			else if(e[2][i].a==y)
			{
				l2l=2;
				l2=i;
			}
		}
//		cout<<e[f][f1].t<<endl<<e[1][myx].t<<endl<<e[2][myy].t<<endl<<e[l2l][l2].t<<endl;
		if((f==1&&l==1)||(f==2&&l==2)) sum=w[x]+e[f][f1].t+e[l][l1].t+w[y];
		else sum=w[x]+e[f][f1].t+e[1][myx].t+e[2][myy].t+e[l2l][l2].t+w[y];
		cout<<sum<<endl;
	}
	return 0;
}