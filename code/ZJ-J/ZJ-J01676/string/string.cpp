#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt=0;
string s;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		ll x;
		char c;
		cin>>x;
		cin>>c;
		for(int j=1;j<=x;j++)
			s+=c;
	}
	ll i=0,j=s.size()-1;
	while(i<=j) {
		if(s[i]!=s[j]) {
			s[j]=s[i];
			cnt++;
		}
		i++;
		j--;
	}
	cout<<cnt;
	return 0;
}
