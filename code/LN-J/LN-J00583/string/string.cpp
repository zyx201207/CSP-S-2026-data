#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s="";
	int sum=0;
	while(n--){
		int x;
		cin>>x;
		sum+=x;
		char c;
		cin>>c;
		for(int i=1;i<=x;i++) s.push_back(c);
	}
	int l=0,r=sum-1;
	int ans=0;
	while(l<=r){
		if(s[l]!=s[r]) ans++;
		l++; r--;
	}
	cout<<ans;
	return 0;
}
