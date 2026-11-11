#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int n;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll len;
		char c;
		cin>>len>>c;
		for(int i=1;i<=len;i++){
			s+=c;
		}
	}
//	cout<<s;
	ll siz=s.size();
	for(ll i=0;i<siz/2;i++){
		if(s[i]!=s[siz-i-1]){
//			cout<<'\n'<<s[i]<<' '<<s[siz-i-1]<<'\n';
//			cout<<i<<' '<<siz-i-1<<'\n';
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
