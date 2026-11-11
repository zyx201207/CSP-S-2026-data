#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,Len=0;
	cin>>n;
	string s;
	while(n--){
		int k;
		char c;
		cin>>k>>c;
		for(int i=1;i<=k;i++)s+=c;
		Len+=k;
	}
	int len=Len/2;
	s=' '+s;
	int ans=0;
	for(int i=1;i<=len;i++){
		if(s[i]!=s[Len-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}