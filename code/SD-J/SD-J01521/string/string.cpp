#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int ans;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) {
		int m;cin>>m;
		string a;cin>>a;
		for(int i=1; i<=m; i++) s+=a;
	}
	int len=s.size();
	int l=0,r=len-1,mid=len>>1;
	while(l<=mid) {
		if(s[l]!=s[r]){
			ans++;
			s[r]=s[l];
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
/*
	2
	2 a
	3 a
6 
1000000000 a 
1000000000 a 
1000000000 a 
1000000000 b 
1000000000 b 
1000000000 b
*/

