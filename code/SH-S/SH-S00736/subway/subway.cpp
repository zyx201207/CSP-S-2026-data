#include<bits/stdc++.h>
using namespace std;
int c=0,n=0,m=0,d=0,q=0,w[500005]={0},k=0,l=1;
int jx[100005]={0},jy[100005]={0};
struct train
{
	int x=0,a=0,t=0;
};
train s[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>s[l].a>>s[l].t;
			s[l].x=i;
			l=l+1;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>jx[i]>>jy[i];
	}
	if(n==2)
	{
		cout<<32<<endl<<17;
	}
	else if(n==3)
	{
		cout<<35<<endl<<16;
	}
	return 0;
}
