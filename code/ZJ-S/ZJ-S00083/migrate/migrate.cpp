#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,d,a[2000005],pre[2000005],sum[2000005],f[2000005],g[2000005],nxt[2000005];
bool mark[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n+1;i++)sum[i]=f[i]=g[i]=0;
		for(int i=1;i<=n;i++){
			int x=lower_bound(a+1,a+n+1,a[i]-d)-a;
			int y=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			sum[y]++;pre[i]=x;nxt[i]=y;
			if(x<i&&(i==n||a[x]+d<a[i+1]))mark[i]=1;
			else mark[i]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			f[i]=g[i]=0;
			if(mark[i]){
				f[i]=f[pre[i]]+sum[i];
				g[i]=g[pre[i]];
				ans+=g[pre[i]];
				if(nxt[pre[i]+1]==i&&pre[i]!=i)g[i]+=f[pre[i]+1];
				if(pre[i]!=i-1&&pre[i]!=i)ans+=f[pre[i]+1],f[pre[i]+1]=0;
				
			}
			else {
				f[i]=sum[i],g[i]=0;
				ans+=g[pre[i]];
				if(pre[i]!=i-1&&pre[i]!=i)ans+=f[pre[i]+1];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
10 22
0 7 14 21 28 35 42 49 56 63

0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
*/