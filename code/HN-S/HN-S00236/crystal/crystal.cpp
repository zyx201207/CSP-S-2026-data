#include<bits/stdc++.h>
#define ll long long int
#define ci const int
using namespace std;
ci csps=5e5+5;
ll a[csps];
ll is_A(ll num){
	ll cnt=0,dome=0;
	bool flag=false;
	for(ll i=1;i<3037000500;i++){
		if(i%2==0){
			if((i/2)*(i+1)==num){
				cnt=i;
				flag=true;
				break;
			}
		}else{
			if(i*((i+1)/2)==num){
				cnt=i;
				flag=true;
				break;
			}
		}
		if(i%2==0){
			if((i/2)*(i+1)>num){
				dome=i-1;
				break;
			}
		}else{
			if(i*((i+1)/2)>num){
				dome=i-1;
				break;
			}
		}
	}
	if(flag){
		return cnt;
	}else{
		return -dome;
	}
}
ll is_B(ll num2,ll zz){
	ll cnt2=0,dome2=0,ap;
	bool flag2=false;
	num2=num2/zz;
	for(ll i=1;i<3037000500;i++){
		if(i%2==0){
			if((i/2)*(i+1)==num2){
				cnt2=i;
				flag2=true;
				break;
			}
		}else{
			if(i*((i+1)/2)==num2){
				cnt2=i;
				flag2=true;
				break;
			}
		}
		if(i%2==0){
			if((i/2)*(i+1)>num2){
				dome2=i-1;
				break;
			}
		}else{
			if(i*((i+1)/2)>num2){
				dome2=i-1;
				break;
			}
		}
	}
	if(flag2){
		return cnt2;
	}else{
		return -dome2;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll n,m,asdfghjkl=0,ans=0,b,cspj=0,csp=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i){
			asdfghjkl=1;
		}
	}
	if(asdfghjkl==0){
		ll phigros=is_A(m);
		if(phigros>0){
			ans=phigros;
			if(ans>a[n]){
				cout << n;
				return 0; 
			}else{
				cout << ans+1;
				return 0; 
			}
			
		}else{
			ans=-phigros;
			if(ans>a[n]){
				cout << n;
				return 0; 
			}else{
				cout << ans+1;
				return 0; 
			}
		}
	}
	csp=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=csp){
			cspj=1;
		}else{
			csp=a[i]-a[i-1];
		}
	}
	if(cspj==0){
		ll phigros=is_B(m,csp);
		if(phigros>0){
			ans=phigros;
			if(ans>a[n]){
				cout << n;
				return 0; 
			}else{
				cout << ans+1;
				return 0; 
			}
			
		}else{
			ans=-phigros;
			if(ans>a[n]){
				cout << n;
				return 0; 
			}else{
				cout << ans+1;
				return 0; 
			}
		}
	}
	cout << n;
	return 0;
}
