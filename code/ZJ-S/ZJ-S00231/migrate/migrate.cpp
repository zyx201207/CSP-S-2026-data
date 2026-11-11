#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,t,ans,a[2000005],f[2000005],d[2000005];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) f[j]=d[j]=0;
			f[i]=1;
			for(int j=i+1;j<=n;j++){
				int pos=j,l=i,r=j-1,mi;
				while(l<=r){
					mi=(l+r)/2;
					if(a[j]-a[mi]<=m){
						r=mi-1;
						pos=mi;
					}
					else l=mi+1;
				}
				d[j]=d[pos]+1;
				for(int k=pos;k<=min(pos+2,j-1);k++){
					if(d[k]==d[pos]) f[j]+=f[k];
				}
				if(f[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
