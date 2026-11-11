#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=3e2+10;
int n,d,x[N],f[N][N];
void solve(){
	memset(f,0,sizeof f);
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int r=x[i]+d;
		for(int j=i+1;j<=n;j++){
			if(x[j]<=r)
				continue;
			int l=x[j]-d,sum=0;
			for(int k=i+1;k<j;k++)
				if(x[k]>=l&&x[k]<=r)
					sum++;
			f[i][j]=sum;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]==2) ans++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++)
				if(f[i][j]==1&&f[j][k]==2) ans++;
			for(int k=j-1;k>0;k--)
				if(f[i][j]==1&&f[j][k]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}