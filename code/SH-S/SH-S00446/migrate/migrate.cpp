#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c,T,n,d,a[2000010],dp1[5010][5010],dp2[5010][5010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ll ans=0;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				dp1[i][j]=0,dp2[i][j]=0;
			}
		}
		for(ll i=1;i<=n;i++){
			dp1[i][i]=0,dp2[i][i]=1;
			for(ll j=i+1;j<=n;j++){
				ll k=j;
				while(a[j]-a[k-1]<=d && k>i) k--;
				dp1[i][j]=dp1[i][k]+1;
				for(;k<j;k++){
					if(dp1[i][k]+1!=dp1[i][j]) break;
					dp2[i][j]+=dp2[i][k];
				}
				if(dp2[i][j]==2) ans++;
				if(dp2[i][j]==0) break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
