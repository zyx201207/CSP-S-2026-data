#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int CT,T,n,d,a[N],nxt[N],lst[N],ans,dp[N],sum[N],s[N],pos[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&CT,&T);
	while(T--){
		scanf("%lld %lld",&n,&d),lst[n+1]=n+1,nxt[0]=0,ans=0;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),nxt[i]=i,lst[i]=i;
		for(int i=1;i<=n;i++){
			nxt[i]=max(nxt[i],nxt[i-1]);
			while(nxt[i]<n&&a[nxt[i]+1]-a[i]<=d) nxt[i]++;
		}
		for(int i=n;i>=1;i--){
			lst[i]=min(lst[i],lst[i+1]);
			while(lst[i]>1&&a[i]-a[lst[i]-1]<=d) lst[i]--;
		}
		for(int i=1;i<=n;i++){
			pos[0]=i;
			for(int j=1;j<=n;j++) pos[j]=nxt[pos[j-1]];
			for(int j=1;j<=i;j++) dp[j]=0,sum[j]=(j==i),s[j]=s[j-1]+sum[j];
			for(int j=i+1;j<=n;j++){
				if(lst[j]>=j) break;
				dp[j]=dp[lst[j]]+1;
				sum[j]=s[pos[dp[lst[j]]]]-s[lst[j]-1];
				s[j]=s[j-1]+sum[j];
				ans+=(sum[j]==2);
			} 
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
