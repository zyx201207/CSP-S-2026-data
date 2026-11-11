#include<bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const ll Maxn=1e5+10;
const ll Mod=1e9;

ll n;
vector<ll> a;
vector<char> c;
ll totle;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=0;i<n;i++){
		ll na;
		char nc;
		cin>>na>>nc;
		c.push_back(nc);
		a.push_back(na);
		totle+=na; 
	}
	ll midd=totle/2;
	ll ans=0;
	ll und=0;
	
	for(ll i=0;i<n;i++){
		if(und>=midd){
			break;
		} 
		ll count=a[i];
		for(ll j=n-1;j>=0;j--){
			if(count==0){
				break;
			}
			if(c[j]==c[i]){
				if(count<a[j]){
					a[j]-=count;
					break; 
				}
				else{
					count-=a[j];
					n--;
				}
			}
			else{
				if(a[j]>count){
					a[j]-=count;
					ans+=count;
					break;
				}else{
					ans+=a[j];
					count-=a[j];
					n--;
				}
			}
		}
		und+=a[i];
	}
	cout<<ans;
	return 0;
}


