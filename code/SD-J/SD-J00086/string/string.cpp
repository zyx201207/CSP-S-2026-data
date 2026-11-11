#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,x,ans;
string s;
char c;
void solve(){
	for(int l=0,r=s.size()-1;l<=r;l++,r--)
		if(s[l]!=s[r])++ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x>>c;
		s+=string(x,c);
	}
	solve();
	cout<<ans;
	return 0;
}
