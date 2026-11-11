#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,ans;
string s;
signed main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a>>c;
		for(int j=t;j<t+a;j++) s[j]=c;
		t+=a;
	}
	for(int i=0;i<=t/2;i++){
		if(s[i]!=s[t-i-1]) ans++;
	}
	cout<<ans<<"\n";
	
	return 0;
}
