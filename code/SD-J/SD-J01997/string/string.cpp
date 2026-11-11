#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(string s){
	string s1=s;
	reverse(s.begin(),s.end());
	return (s==s1);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;string s;cin>>n;
	while(n--){
		int x;char c;cin>>x>>c;
		//s=s+string(c,x);
		while(x--)s=s+c;
	}
	if(check(s))cout<<0;
	else{
		int cnt=0,l=s.size();
		s=" "+s;
		for(int i=1;i<=l/2;i++)if(s[i]!=s[l-i+1])cnt++;
		cout<<cnt;
	}
	return 0;
}
