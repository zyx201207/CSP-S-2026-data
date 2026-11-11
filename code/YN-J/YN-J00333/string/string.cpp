#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll a[N];
char c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	string l,r;
	for(int i=1;i<=s.size()/2;i++){
		l+=s[i];
	}
	for(int i=s.size()/2+1;i<=n;i++){
		r+=s[i];
	}
	if(l==r){
		cout<<0;
	}
	return 0;
}
