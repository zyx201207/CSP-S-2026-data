#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n,a,sum,cnt,ans;
char c,cx[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;++i){
		scanf("%lld %c",&a,&c);
//		printf("%lld %c\n",a,c);
		for(int i = 1;i <= a;++i){
			cx[++cnt] = c;
		}
	}
//	printf("%s\n%lld\n",cx + 1,cnt);
	if(cnt % 2 == 1){
		for(int i = 1;i <= cnt / 2;++i){
			if(cx[i] != cx[cnt - i + 1]) ans += 1;
		}
		printf("%lld",ans);
	}else{
		for(int i = 1;i <= cnt / 2;++i){
			if(cx[i] != cx[cnt - i + 1]) ans += 1;
		}
		printf("%lld",ans);
	}
	return 0;
}
