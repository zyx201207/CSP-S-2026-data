#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
string s;

int ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++) s+=c;
	}
	ll len=0;
	if((s.size())%2!=0) len=(s.size()+1)/2;
	else len=(s.size())/2;
	for(int i=0;i<len;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
