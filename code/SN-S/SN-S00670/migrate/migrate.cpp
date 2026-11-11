#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+7;
int c,t;
int zubi[N];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>zubi[i];
	int ans=0;
	for(int k1=2;k1<=n-1;k1++){
		for(int k2=k1+1;k2<=n-1;k2++){
			for(int i=1;i<k1;i++){
				for(int j=k2+1;j<=n;j++){
					if(zubi[k1]-zubi[i]>d) continue;
					if(zubi[j]-zubi[k1]>d) continue;
					if(zubi[k2]-zubi[i]>d) continue;
					if(zubi[j]-zubi[k2]>d) continue;
					if(zubi[j]-zubi[i]>d) ans++;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
