#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;

int n,m,a[N],idd[N],ans,len,noww[N],lenn;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);len=n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),idd[i]=i;
	for(int i=30;i>=0;i--){
		lenn=0LL;
		for(int j=1;j<=len;j++){
			if((a[idd[j]]&(1<<i))!=0) noww[++lenn]=idd[j];
		}
		if(lenn>=m){
			ans+=(1<<i);
			len=lenn;
			for(int j=1;j<=len;j++) idd[j]=noww[j];
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
4 2
3 15 12 12
*/
