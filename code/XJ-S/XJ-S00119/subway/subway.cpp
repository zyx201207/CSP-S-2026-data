#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+5; 
long long c, n, m, d, q,x,y,ans=0,sum=0;
long long w[N],a[N][N],k[N],t[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
		for(int i=1;i<=n;i++)
		cin>>k[i];
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		cin>>a[i][j]>>t[i][j];
		cin>>x>>y;
		for(int i=1;i<=m;i++)
		for(int j=n;j>=1;j--)
		{
			ans+=w[i]+t[i][i]+(t[i][j]+t[j][j]);
			ans+=t[j][j+1]+w[j];
			sum+=w[i]|+t[i][i]+t[i][j]+w[j];
		}
		cout<<ans<<sum;
	return 0;
}
