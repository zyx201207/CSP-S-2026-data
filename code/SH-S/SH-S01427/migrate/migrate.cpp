#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k,c,n,a[2000009];
signed main(){
	ios::sync_with_stdio(false); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		int nw=0;lst=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i+3]-a[i]>k and a[i+2]-a[i]<=k and a[i+3]-a[i+1]<=k){
				ans+=lst*nw;
				lst=nw;
				i=i+4;
			}else nw++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
