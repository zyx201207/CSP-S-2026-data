#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[200010]; 
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a[i]=x;
		char y;
		cin>>y;
		for(int j=0;j<x;j++){
			s=s+y;
		}
	}
	int f=0;
	for(int i=0;i<n;i++){
		if(s[i]!=s[i-1]){
			f=1;
		} 
	} 
	if(f==0){
		cout<<0;
		return 0;
	}
	int l=0,r=s.size()-1;
	while(r>=l){
		if(s[r]!=s[l]){
			s[r]=s[l];
			ans++;
		}
		l++;
		r--;
	} 
	cout<<ans;
	return 0; 
} 
