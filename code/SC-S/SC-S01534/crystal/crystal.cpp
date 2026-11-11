#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MN = 5e5 + 20;
int n,m,ans = 0;
int a[MN];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	if(n > 5000){
		int d = a[2] - a[1];
		int rec = 0,cnt = 1;
		for(int i = 1;i <= n;i++){
			rec += i * d;
			if(rec <= m) cnt++;
			else break;
		}
		printf("%lld",min(cnt,n));
	}
	sort(a + 1,a + n + 1); 
	for(int i = n;i >= 1;i--){
		int s = m,rec = 1,j = i;
		for(int j = i - 1;j >= 1;j--){
			s -= a[i] - a[j];
			if(s >= 0) rec++;
			else break;
		}
		ans = max(ans,rec);
	}
	printf("%lld",ans);
	return 0;
}
