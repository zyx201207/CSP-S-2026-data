#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[s.size()-i-1]!=s[i]){
			ans++;
		}
	}
	cout<<ans/2<<'\n';
	return 0;
}
