#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],c[N],maxn;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) c[i]=a[i+1]-a[i];
	//for(int i=1;i<=n;i++) printf("%lld ",c[i]);
	//printf("\n");
 	for(int i=1;i<=n;i++){
		int cnt=0,j=i,sum=1,nown=0;
		//printf("%lld:",i);
		while(--j){
			nown+=c[j];
			if(cnt+nown>m) break;
			cnt+=nown;
			++sum;
			//printf("%lld %lld;",nown,cnt);
		}
		//printf(" %lld\n",sum);
		maxn=max(maxn,sum);
	}
	//printf("\n");
	printf("%lld",maxn);
	return 0;
}
