#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll ans,a[N],s[N];
ll n;
ll l,r;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c;
		s[i]=c-'a'+1;
	}
	l=1;
	r=n;
	while(l < r){
		if(s[l] == s[r]){
			if(a[l] < a[r]){
				a[r] -= a[l];
				++l;
			}
			else if(a[l] == a[r]){
				++l;
				--r;
			}
			else{
				a[l] -= a[r];
				--r;
			}
		}
		else{
			if(a[l] < a[r]){
				ans += a[l];
				a[r] -= a[l];
				++l;
			}
			else if(a[l] == a[r]){
				ans += a[l];
				++l;
				--r;
			}
			else{
				ans += a[r];
				a[l] -= a[r];
				--r;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
