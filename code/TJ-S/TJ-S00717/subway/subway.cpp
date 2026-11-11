#include <bits/stdc++.h>
using namespace std;
const int maxn=500005,mmaxn=21505,bbig=1000000000;
#define int long long
int c,n,m,d,q,w[maxn],k,id=1,t,a;

int flo[mmaxn/2*(mmaxn-1)];

int turn(int i,int j)
{
	if(i<j)
	{
		swap(i,j);
	}
	return((i-2)*(i-1)/2+j);
}
void floyd()
{
	for(int i=1;i<=n+m;i++)
	{
		for(int j=1;j<n+m;j++)
		{
			for(int r=j+1;r<=n+m;r++)
			{
				if(j==i||r==i)
				{
					continue;
				}
				int xy1=turn(j,i),xy2=turn(i,r),xy3=turn(j,r);
				if(flo[xy1]!=bbig&&flo[xy2]!=bbig)
				{
					flo[xy3]=min(flo[xy3],flo[xy2]+flo[xy1]);
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int st,ed;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n+m;i++)
	{
		for(int j=1;j<=(n+m);j++)
		{
			flo[turn(i,j)]=bbig;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			int xy=turn(i+m,a);
			flo[xy]=t;
		}
	}

	floyd();
	for(int i=1;i<=q;i++)
	{
		cin>>st>>ed;
		cout<<flo[turn(st,ed)]+w[ed]+w[st]<<endl;
	}
	return 0;
}
