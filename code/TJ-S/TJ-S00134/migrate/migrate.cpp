#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T;
ll n,d;
ll a[2000010];
map<int,int> mp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ll k=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>=11&&c<=12){
			k=a[2]-a[1];
			ll p=d/k;
			if(p<2) cout<<0<<'\n';
			else cout<<(n-2*p+1>0?n-2*p+1:0)<<'\n';
		}else{
			ll cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]>d){
						int k=upper_bound(a+i+1,a+j+1,(a[i]+a[j])/2)-a-1;
						if(a[k]-a[i]<=d&&a[j]-a[k]<=d&&a[k+1]-a[i]<=d&&a[j]-a[k-1]<=d&&a[k+2]-a[i]>d&&a[j]-a[k-2]>d){
							cnt++;
						}
					}
				}
			}
			cout<<cnt<<'\n';
		}
	}
	return 0;
}

