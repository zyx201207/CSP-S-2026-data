#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n,ans,L;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x; char c; cin>>x>>c;
		for(int j=1;j<=x;j++) s+=c;
		L+=x;
	}
	for(int i=0;i<(L+1)/2;i++){
		if(s[i]!=s[L-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
