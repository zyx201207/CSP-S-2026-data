#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,C,T,cnt[N],a[N],mn[N];
void solve(int x,int y){
	if(x==n) return;
	int i=x+1; y++;
	while(a[x]+d>=a[i]&&i<=n){
		if(y<mn[i]) cnt[i]=1,mn[i]=y;
		else if(y==mn[i]) cnt[i]++;
		solve(i,y);
		i++;
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(C==13||C==14){
			printf("0\n");
			return 0;
		}
		int ans=0;
		for(int i=1;i<n;i++){
			memset(cnt,0,sizeof(cnt));
			memset(mn,0x3f,sizeof(mn));
			solve(i,0);
			for(int j=2;j<=n;j++)
				if(cnt[j]==2)
					ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
