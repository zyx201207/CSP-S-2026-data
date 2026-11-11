#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005];
bool b=1,c=1,d=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>100){
			b=0;
		}
		if(a[i]!=i){
			c=0;
		}
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				d=0;
			}
		}
	}
	sort(a+1,a+n+1);
	ll cnt=0;
	if(b){
		for(int h=0;h<=100;h++){
			ll y=0,t=0,p=0;
			for(int i=1;i<=n;i++){
				if(a[i]<=h){
					y=i;
				}else{
					break;
				}
			}
			for(int i=y;i>=1;i--){
				t+=(h-a[i]);
				if(t>m){
					break;
				}
				p++;
			}
			cnt=max(cnt,p);
		}
	}else if(c){
		for(int i=1;i<=n;i++){
			ll kk=i*(i-1)/2;
			if(m>=kk){
				cnt=i;
			}else{
				break;
			}
		}
	}else if(d){
		for(int i=1;i<=n;i++){
			ll kk=i*(i-1)/2*(a[i+1]-a[i]);
			if(m>=kk){
				cnt=i;
			}else{
				break;
			}
		}
	}else{
		for(ll i=1;i<=n;i++){
		ll t=0,p=0;
			for(ll j=i;j>=1;j--){
				t+=(a[i]-a[j]);
				if(t>m){
					break;
				}
				p++;
			}
			cnt=max(cnt,p);
		}	
	}
	cout<<cnt;
	return 0;
}
