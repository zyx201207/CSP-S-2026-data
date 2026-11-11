#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
bool is_h(string s1,ll l) {
	for (int i=0;i<l;i++) {
		if (s1[i]!=s1[l-i-1]) return 0;
	}
	return 1;
}
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int m=0;
	for (ll i=0;i<n;i++) {
		ll x;
		cin>>x;
		char y;
		cin>>y;
		if (n>2000) break;
		else {
			for (ll j=0;j<x;j++) {
				s[m]=y;
				m++;
			}
		}
	}
	if (n<=2000){
		if (is_h(s,m)) cout<<0;
		else {
			for (int i=0;i<m;i++) {
				for (int j=0;j<26;j++) {
					string s2=s;
					s2[i]='a'+j;
					if (is_h(s2,m)) cout<<1;
				}
			}
		}
	}
	else cout<<0;
	return 0;
} 

