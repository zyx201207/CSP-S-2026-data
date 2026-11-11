#include<bits/stdc++.h>
using namespace std;
int c,T,n;
long long d;
const int N=2e6+10;
long long x[N],f[N],g[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	long long ans=0;
	for(int i=1;i<=n;i++){
		f[i]=0;g[i]=1;
	    for(int j=i+1;j<=n;j++){
	    	f[j]=1e18;g[j]=0;
			for(int k=j-1;k>=i;k--){
				if(x[j]-x[k]>d) break;
				if(f[k]+1<f[j]){
					f[j]=f[k]+1;
					g[j]=g[k];
				}else if(f[k]+1==f[j]) g[j]+=g[k];
			}
		    if(g[j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}