#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+20;
ll c,n,m,d,q,w[N],t[2000][2000],a[2000][2000],k[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
		
	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		vector<ll>lnx,lny;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]==x) lnx.push_back(i);
				if(a[i][j]==y) lny.push_back(i);
			}
		}
		ll ans=INT_MAX;
		for(int i=0;i<lnx.size();i++)//all link through x
		{
			for(int j=0;j<lny.size();j++)//all link through y
			{
				if(lnx[i]==lny[j])
				{
					ll wd=w[x]+t[lnx[i]][x]+t[lnx[i]][y]+w[y];
					ans=min(ans,wd);
				}
				for(int l=1;l<=k[lnx[i]];l++)//all link through x(station)
				{
					for(int z=1;z<=k[lny[j]];z++)//all link through y(station)
					{
						
						if(a[lnx[i]][l]==a[lny[j]][z])
						{
							ll ch=a[lnx[i]][l];
							//x.kou->x.ti->x.st
							ll wd=w[x]+t[lnx[i]][x]+t[lnx[i]][ch]+t[ch][ch]+t[lny[j]][y]+w[y];
							//cout<<w[x]<<" "<<t[lnx[i]][x]<<" "<<t[lnx[i]][ch]<<" "<<t[ch][ch]<<" "<<t[lny[j]][y]<<" "<<w[y]<<"\n";
							//cout<<lny[j]<<" "<<y<<endl;
							ans=min(ans,wd);
							//cout<<x<<"->"<<ch<<"->"<<y<<endl;
						}
						//cout<<a[lnx[i]][l]<<" "<<a[lny[j]][z]<<endl;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
