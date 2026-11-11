#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	ll a;
	char b;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a);
		scanf("%s",&s);
		s.append(a,b);
	}
	ll l=0;
	ll len=s.size();
	ll r=len-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
