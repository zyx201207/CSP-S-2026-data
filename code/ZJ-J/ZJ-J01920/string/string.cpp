#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s="";
ll n,l,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--){
		ll x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s[l]+=c;
			l++;
		}
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
