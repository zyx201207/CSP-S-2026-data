#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[20005];
char c[20005];
bool hw(string s){
	for(ll i=0;i<=s.size();i++){
		if(s[i]=s[s.size()-i-1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll len=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
//	for(ll i=1;i<=n;i++){
//		cout<<c[i];
//	}
	ll cnt=0;
	char x[len];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=a[i];j++){
		    x[cnt++]=c[i];
		}
	}
	if(hw(x)){
		cout<<0;
	}else{
		cout<<len/2;
	}
	return 0;
}
