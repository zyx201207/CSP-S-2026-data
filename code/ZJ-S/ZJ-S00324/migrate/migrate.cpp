#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N],ans,ifa,minn=LLONG_MAX;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		ifa=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])ifa=0;
			if(i>2)minn=min(minn,a[i]-a[i-1]);
		}
		if(d<minn)cout<<0<<endl;
		else if(ifa){
			cout<<max(0ll,n-2*(d/(a[2]-a[1]))+1)<<endl;
		}else if(n*n<1e8){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if((a[j]-a[i])/d==1&&(a[j]-a[i])%d==d-1&&(a[j]-a[i])/d+1<=j-i){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}else cout<<0<<endl;
	}
	return 0;
}
