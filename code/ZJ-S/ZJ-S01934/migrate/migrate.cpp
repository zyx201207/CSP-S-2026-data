#include<bits/stdc++.h>
using namespace std;
#define int long long
int g[5005][5005],a[5005];
void solve(){
	int n,d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]-a[i]<=d) g[i][j]=1;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			} 
			int cnt=0;
			for(int k=i;k<j;k++){
				if(g[i][j]==g[i][k]+g[k][j]) cnt++;
			}
			if(cnt==2) ans++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve(); 
	return 0;
}
/*

*/
