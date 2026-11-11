#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
long long n, m;
long long a[N], b[N];
long long ans, cnt;
bool cmp(int a, int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int mask=29;mask>=0;mask--){
		cnt=0;
		for(int i=1;i<=n;i++)
			if(((a[i]>>mask)&1))
				b[++cnt]=a[i];
		if(cnt>=m){
			sort(b+1,b+cnt+1,cmp);
			ans=b[1];
			for(int i=2;i<=m;i++)
				ans&=b[i];
			printf("%lld",ans);
			return 0;
		}
	}
	printf("0");
	return 0;
}
