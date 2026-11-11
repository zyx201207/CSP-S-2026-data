#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s='0';
	for(int i=1;i<=n;++i){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;++j)s+=c;
	}
	int len=s.size()-1,ans=0;
	for(int i=1;i<=(len)/2;++i){
		if(s[i]!=s[len-i+1])++ans;
	}
	cout<<ans;
	return 0;
}
