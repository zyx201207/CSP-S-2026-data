#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		while(a--){
			s+=b;
		}
	}
	int l=s.size();
	s=' '+s;
	for(int i=1;i<l/2;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
