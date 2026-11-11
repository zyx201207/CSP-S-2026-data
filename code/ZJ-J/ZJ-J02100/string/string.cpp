//T2 string 解法1 预期70
//Trick||Treat!
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,x,len,ans;
char c;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+=" ";
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		len+=x;
		for(int j=1;j<=x;j++) s+=c;
	}
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]) ans++;
	}
	cout<<ans;
}