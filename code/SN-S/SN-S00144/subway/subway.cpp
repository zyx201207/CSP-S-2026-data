#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;
ll c,n,m,d,q;
ll w[maxn],k[510],a[510][maxn],t[510][maxn],x[maxn],y[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++){
		ll ans=w[x[i]]+w[y[i]];
		for(int j=x[i];j<=y[i]+1;j++){
			ll minn=1e9+10;
			for(int l=1;l<=n;l++){
				ll csp=0;
				for(int h=1;h<=k[l];h++){
					if(a[l][h]==j){
						csp+=t[l][h];
					}
				}
				if(csp!=0){
					minn=min(csp,minn);
				}
			}
			ans+=minn;
		}
		cout<<ans<<"\n";
 	}
	return 0;
}
