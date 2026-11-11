#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
ll pan(string S){
	ll ans=0;
	string s=S;
	ll n=s.size();
	for(ll i=0;i<n/2;i++){
		if(s[i]!=s[n-1-i]){
			ans++;
		}
	}return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int a;char c;
		cin>>a>>c;
		while(a--)s+=c;
	}
	cout<<pan(s);
	return 0;
}

