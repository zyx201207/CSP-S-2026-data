#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l,ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
		l+=a;
	}
	// cout<<s<<" "<<l<<endl;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	cout<<ans<<endl;
}