#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s="";
	for(int i=1;i<=n;i++){
		int x;
		string t;
		cin >> x >> t;
		for(int i=1;i<=x;i++){
			s+=t;
		}
	}
	long long ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			s[s.size()-i-1]=s[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
