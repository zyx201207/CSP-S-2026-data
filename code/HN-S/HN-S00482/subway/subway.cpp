#include<bits/stdc++.h>
using namespace std;
int a[505],xl[505][505][3],xlzds[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>xlzds[i];
		for(int j=1;j<=xlzds[i];j++)
		cin>>xl[i][j][1]>>xl[i][j][2];
	}
	for(int i=1;i<=q;i++)
	{
		int l,r,minn=0x3f3f3f;
		cin>>l>>r;
		for(int j=1;j<=n;j++)
		{
			bool w=0,e=0,cnt=0;
			for(int k=1;k<=xlzds[i];k++)
			{
				if(xl[j][k][1]==l)
				w=1;
				if(w)
				cnt+=xl[j][k][2];
				if(xl[j][k][1]==r)
				{
					e=1;
					break;
				}
			}
			if(w && e)
			minn=min(cnt+a[l]+a[r],minn);
		}
		cout<<minn;
	}
	return 0;
}
