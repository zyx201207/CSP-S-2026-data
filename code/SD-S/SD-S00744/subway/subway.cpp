#include<bits/stdc++.h>
using namespace std;
int cc,n,m,dd,qq;
int w[500005];
long long f[405][405];
vector<int> a[505];
vector<int> t[505];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cc>>n>>m>>dd>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==j) f[i][j]=0;
			else f[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int kk;
		cin>>kk;
		for(int j=1;j<=kk;j++)
		{
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
		for(int j=0;j<a[i].size()-1;j++)
		{
			for(int z=j+1;z<a[i].size();z++)
			{
				long long u=t[i][j]+t[i][z];
				f[a[i][j]][a[i][z]]=min(f[a[i][j]][a[i][z]],u);
				f[a[i][z]][a[i][j]]=f[a[i][j]][a[i][z]];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			for(int z=1;z<=m;z++)
			{
				for(int g=1;g<=m;g++)
				{
					f[z][g]=min(f[z][g],f[z][a[i][j]]+f[a[i][j]][g]);
					f[g][z]=f[z][g];
				}
			}
		}
	}
	while(qq--)
	{
		int l,r;
		cin>>l>>r;
		long long ans=f[l][r]+w[l]+w[r];
		cout<<ans<<endl;
	}
	return 0;
}
