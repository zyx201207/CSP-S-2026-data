#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int ans,n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		int x;
		char ch,c;
		scanf("%lld%c%c",&x,&ch,&c,&ch);
		for(int j=1;j<=x;j++){
			s+=c;
		}	
	}
	for(int i=0;i<s.size()/2;i++)if(s[i]!=s[n-i+1])ans++;
	printf("%lld",ans);
	return 0;
}


