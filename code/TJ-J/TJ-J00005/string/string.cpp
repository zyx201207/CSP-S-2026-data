#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,cnt=0;
	cin >> n;
	string s="",s2="";
	for(int i=0;i<n;i++){
		ll a;
		char c;
		cin >> a >> c;
		while(a--) s+=c;
	}
	s2=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]!=s2[i]) cnt++;
	}
	cout << cnt/2;
}
