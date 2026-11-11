#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans(string s){
	int l=0,r=s.size()-1,cnt=0;
	while(l<r){
		if(s[l]!=s[r]) cnt++;
		l++,r--;
	}
	return cnt;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	string s="";
	for(int i=1;i<=n;i++){
		int v;
		char c;
		cin >> v >> c;
		for(int i=1;i<=v;i++) s+=c;
	} 
	cout << ans(s);
	return 0;
}

