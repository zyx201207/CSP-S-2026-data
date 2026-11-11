#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],cnt;
char b[200005];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]<=500){
			for(ll j=1;j<=a[i];j++){
				s+=b[i];
			}
		}else{
			string t,t1,t2;
			for(ll j=1;j<=100;j++){
				t+=b[i];
			}
			for(ll j=1;j<=100;j++){
				t1+=t;
			}
			for(ll j=1;j<=100;j++){
				t2+=t1;
			}
			ll z1=a[i]/1000000,z2=a[i]%1000000/10000,z3=a[i]%10000/100,z4=a[i]%100;
			for(ll j=1;j<=z1;j++){
				s+=t2;
			}
			for(ll j=1;j<=z2;j++){
				s+=t1;
			}
			for(ll j=1;j<=z3;j++){
				s+=t;
			}
			for(ll j=1;j<=z4;j++){
				s+=b[i];
			}
		}
	}
	ll l=s.size();
	s=" "+s;
	for(ll i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]) cnt++;
	}
	cout<<cnt;
	return 0;
}