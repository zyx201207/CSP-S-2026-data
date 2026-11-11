#include<bits/stdc++.h>
using namespace std;
int main(){
	#define ll long long
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,x,cnt=0;
	char y;
	string s;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s+=y;
		}
	}
	//cout<<s;
	ll l=s.size();
	for(ll i=1;i<=l/2;i++){
		if(s[i-1]!=s[l-i]){
			s[l-i]=s[i-1];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
