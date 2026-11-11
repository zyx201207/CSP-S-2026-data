//SN-S00402 把小煜 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d;
int x[5010];
int f[5010][5010];
int ans;
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) 
		if(x[j]-x[i]<=d) f[i][j]=1;
	for(int l=1;l<=n;l++) for(int i=1;i<=n;i++) 
	{
		int j=i+l;
		if(j>n) break;
		for(int k=i+1;k<j;k++) if(x[j]-x[i]>d) f[i][j]+=f[i][k]*f[k][j];
	}	
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(f[i][j]>=2) ans++;
	cout<<ans*2<<"\n";
	ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	//T3就是滚木滚木滚木滚木
	return 0;
}
