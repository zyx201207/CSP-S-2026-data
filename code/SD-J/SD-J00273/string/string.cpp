#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s="";
	int l=0;
	for(int i=1;i<=n;i++) {
		int d;
		char c;
		cin>>d;
		cin>>c;
		for(int j=1;j<=d;j++) {
			s+=c;
		}
		l+=d;
	}
	int mid=0;
	if(l%2==0) mid=l/2-1;
	else mid=(l-1)/2;
	int ans=0;
	for(int i=0;i<=mid;i++) {
		if(s[i]!=s[l-1-i]) {
			ans++;
		}
	}
	cout<<ans;
}
