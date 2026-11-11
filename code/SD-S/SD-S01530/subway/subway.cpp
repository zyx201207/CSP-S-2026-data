#include <bits/stdc++.h>
using namespace std;

const int N=500200;
long long c,n,m,d,q,a[N],k,b[10000][10000],k1,k2,a1,a2,p,w1,w2,num;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>k1>>k2;
			b[i][k1]=k2;
		}
	}	
	while(q--)
	{
		long long ans;
		ans=0;
		cin>>a1>>a2;
		for(int i=1;i<=n;i++)
		{
			if(b[i][a1]!=0)
			{
				if(b[i][a2]!=0)
				{
					ans+=b[i][a1];
					ans+=b[i][a2];
					cout<<ans<<endl;
					break;
				}
			}
		}
		for(int i=1;i<=w1;i++)
		{
			ans=0;
			for(int j=1;j<=w2;j++)
			{
				if(b[1][i]!=0 && b[2][j]!=0)
				{
					ans+=b[1][i]+b[2][j]+b[2][a2];
				}
			}
			ans=min(ans,num);
		}
		if(b[2][a1]!=0)
		{
			if(b[2][a2]!=0)
			{
				ans+=b[2][a1];
				ans+=b[1][a2];
				cout<<ans<<endl;
				continue;
			}
		}
		for(int i=1;i<=w2;i++)
		{
			ans=0;
			for(int j=1;j<=w1;j++)
			{
				if(b[2][i]!=0 && b[1][j]!=0)
				{
					ans+=b[2][i]+b[1][j]+b[1][a2];
				}
			}
			ans=min(ans,num);
		}
		cout<<ans<<endl;
	}
	return 0; 
}
