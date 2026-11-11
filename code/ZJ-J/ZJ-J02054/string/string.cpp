#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,k;
char a;
string s;
	
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>a;
		for(int j=1;j<=k;j++) s+=a;
	}
	
	int l=s.size();
	int ans=0;
	for(int i=0;i<(l+1)/2;++i){
		if(s[i]!=s[l-i-1]) ++ans;
	}
	cout<<ans;
	
	
	return 0;
}
