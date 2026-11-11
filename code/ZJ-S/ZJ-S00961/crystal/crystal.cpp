#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;

int a[N],n,m,ans,pre[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int L=0,R=i+1;
		while(L+1<R){
			int M=(L+R)>>1;
			if(a[i]*(i-M+1)-(pre[i]-pre[M-1])<=m) R=M;
			else L=M;
		}
		ans=max(ans,i-R+1);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
