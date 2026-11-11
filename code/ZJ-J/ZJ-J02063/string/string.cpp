#include<bits/stdc++.h>
#define int long long
using namespace std;
char c;
int x,n,ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		while(x--) s+=c;
	}
	int len=s.size();
	for(int i=0;i<len/2;i++)
		if(s[i]!=s[len-i-1]) ans++;
	cout<<ans;
}
//68 pts
//RP++