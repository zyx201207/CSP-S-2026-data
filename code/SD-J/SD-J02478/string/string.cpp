#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	s+="#";
	for(int i=1;i<=n;i++){
		int x;
		char op;
		scanf("%lld",&x);
		op=getchar();
		for(int j=1;j<=x;j++){
			s+=op;
		}
	}
	int l=s.length();
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]){
			ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
