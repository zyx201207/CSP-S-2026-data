#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[5005],L[5005],f[5005][5005],cnt[5005][5005],ans;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				f[i][j]=1e18;
				cnt[i][j]=0;
			}
		}
		for(ll i=2,j=1;i<=n;i++){
			while(x[i]-x[j]>d){
				j++;
			}
			L[i]=j;
		}
		for(ll i=2;i<=n;i++){
			for(ll j=L[i];j<i;j++){
				f[j][i]=1;
				cnt[j][i]=1;
			}
		}
		ans=0;
		for(ll len=2;len<=n;len++){
			for(ll i=1;i<=n-len;i++){
				ll j=i+len;
				if(f[i][j]<1e18){
					//cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<cnt[i][j]<<'\n';
					continue;
				}
				for(ll k=i+1;k<j;k++){
					if(f[i][k]+f[k][j]<f[i][j]){
						f[i][j]=f[i][k]+f[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
					else if(f[i][k]+f[k][j]==f[i][j]){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
				}
				//cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<cnt[i][j]<<'\n';
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

