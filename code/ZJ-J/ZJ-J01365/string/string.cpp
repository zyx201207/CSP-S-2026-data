#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+5;
ll n,ans;
string s;
struct zf{
	ll len;
	char ch;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i].len>>a[i].ch;
	bool r=1;
	for(ll i=1;i<=(n+1)/2;i++){
		if(a[i].len!=a[n-i+1].len||a[i].ch!=a[n-i+1].ch)r=0;
	}
	if(r){
		cout<<0;
		return 0;
	}
	ll x=n;
	for(ll i=1;i<=(x+1)/2;i++){
		if(a[i].ch!=a[n-i+1].ch){
			ll lenx=min(a[i].len,a[n-i+1].len);
			a[i].len-=lenx;
			a[n-i+1].len-=lenx;
			ans+=lenx;
		}
		
		if(a[i].len==a[n-i+1].len)n-=2;
		else n--;
	}
	cout<<ans;
	return 0;
}