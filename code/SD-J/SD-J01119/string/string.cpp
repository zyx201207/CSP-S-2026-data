#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,f;
string s;
char c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f>>c;
		while(f--) s+=c;}
	for(int i=0;i<s.size()/2;i++) ans+=(s[i]!=s[s.size()-i-1]);
	cout<<ans;
	return 0;}
