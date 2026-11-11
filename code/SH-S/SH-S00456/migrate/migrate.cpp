#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,a[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(ll i=1;i<=n;++i) cin>>a[i];
			if(n-3>0) cout<<n-3<<endl;
			else cout<<0<<endl; 
		}
	}
	else{
		while(t--){
			ans=0;
			cin>>n>>d;
			for(ll i=1;i<=n;++i)cin>>a[i];
			for(int i=1;i<=n-3;++i){
				if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d){
					ans++;
				}
			}
			cout<<ans<<endl;
		} 
	}
	return 0; 
}
