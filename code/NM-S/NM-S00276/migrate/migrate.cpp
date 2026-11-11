#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;ll d;
		cin>>n>>d;
		vector<ll>a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		if(n<=3)cout<<0<<endl;
		if(c==11||c==12){
			ll k=a[1]-a[0];
			ll num=(d/k)*2-1;
			if(num<=2){
				cout<<0<<endl;
				continue;
			}
			ll ans=max(0LL,n-num);
			cout<<ans<<endl;
			continue;
		}
		ll ans=0;
		for(int i=0;i<n-3;i++){
			if(a[i+3]-a[i]>d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
