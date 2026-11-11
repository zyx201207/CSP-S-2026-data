#include <bits/stdc++.h>
using namespace std;
int a[505][50005],ans,b,c,d,k,m,n,q,res1,res2,t[505][50005],w[50005],x,y;
bool A,B;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	A=1;
	B=1;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(k>2)A=0;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			if(t[i][j]!=t[1][1])B=0;
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		if(A==1)
		{
			for(int j=1;j<3;j++)
			{
				if(a[j][1]==x)
				{
					b=1;
					while(x!=y)
					{
						res1+=t[j][b]+t[j][3-b];
						x=a[j][3-b];
						b=3-b;
					}
				}
				if(a[j][2]==x)
				{
					b=2;
					while(x!=y)
					{
						res2+=t[j][b]+t[j][3-b];
						x=a[j][3-b];
						b=3-b;
					}
				}
			}
			ans+=max(res1,res2);
			cout<<ans<<endl;
		}
	}
	return 0;
}
