#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt,n,b=1,ans=0,h,o=1;
string s,k,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){
		ll a;
		char ch;
		cin>>a>>ch;
		ans+=a;
		for(ll i=b;i<=a+b-1;i++){
			s[i]=ch;
		}
		b+=a;
	} 
	h=ans;
	ans=ceil(ans*1.0/2);
	for(ll i=1;i<=h;i++){
		k[i]=s[i];
	}
	for(ll i=h;i>=1;i--){
		for(ll j=o;j<=o;j++){
			l[j]=s[i];
		}
		o++;
	} 
	for(ll i=1;i<=ans;i++){
		if(k[i]!=l[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
