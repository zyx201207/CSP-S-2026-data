#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,i,x,ans,len;
char sum;
string s;
void check(){
	int i;
	for(i=1;i<=len/2;i++) if(s[i]!=s[len-i+1]) ans++;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x>>sum;
		len+=x;
		while(x--) s+=sum;
	}
	s=' '+s;
	check();
	cout<<ans;
	return 0;
}

