#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct zfc{
	ll number;
	char zm;
};
zfc a[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,middle,ans=0;
	cin >> n;
	string s,sq;
	for(ll i=1;i<=n;i++){
		cin >> a[i].number >> a[i].zm;
		for(ll j=1;j<=a[i].number;j++){
			s+=a[i].zm;
		}
	}
	middle=ceil((s.size()/2));
	for(ll i=middle-1;i>=0;i--){
		sq+=s[i];
	}
	for(ll i=middle+1,j=0;i<=s.size();i++,j++){
		if(s[i]!=sq[j])ans++;
	}
	cout << ans;
	return 0;
}