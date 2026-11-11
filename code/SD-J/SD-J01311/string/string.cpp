#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=LONG_LONG_MAX;
char s[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,ans=0;
	cin>>n;
	bool flag;
	while(n--){
		int a;
		char k;
		cin>>a>>k;
		for(int i=cnt;i<=cnt+a;i++){
			s[i]=k;
		}
		cnt+=a;
	}
	if(cnt%2==1){
		for(int i=1;i<=cnt/2;i++){
			if(s[i]!=s[cnt-i+1])ans++;
		}
		cout<<ans-1;
	}
	else{
		for(int i=1;i<=cnt/2;i++){
			if(s[i]!=s[cnt-i+1])ans++;
		}
		cout<<ans;
	}
	return 0;
}
