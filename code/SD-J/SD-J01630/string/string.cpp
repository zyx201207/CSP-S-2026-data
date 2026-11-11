#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+=" ";
	for(int i=1;i<=n;i++){
		char a;
		int len;
		cin>>len>>a;
		for(int j=1;j<=len;j++){
			s+=a;
		} 
	}
	for(int i=1;i<=(s.size()-1)/2;i++){
		if(s[i]!=s[s.size()-i]) ans++;
	}
	cout<<ans;
	return 0;
} 
