#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
const int N=2e6+5;
int x[N],cnt[N];
void solve(){
	int l,sum=0;
	for(int i=1;i<n;i++){
		l=i;cnt[i]=0;
		for(int j=i+1;j<=n;j++){
			while(x[j]-x[l]>d) l++;
			if(cnt[l]==0) cnt[j]=1;
			else if(cnt[l]==1){
				if(l==j-2&&cnt[l+1]==1) cnt[j]=2,sum++;
				else cnt[j]=3;
			}
			else if(cnt[l]==2&&l==j-1) cnt[j]=2,sum++;
			else cnt[j]=3;
		}
	}
	printf("%lld\n",sum);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(n<=5000)
		solve();
		else{
			if(d<=x[2]-x[1]) puts("0");
			else printf("%lld\n",n/2);
		}
	}
	return 0;
}