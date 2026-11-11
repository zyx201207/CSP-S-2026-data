#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9;
int cs,T,n,a[N],b[N],p,len,dp[N],cnt[N],num[N];
long long d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&cs,&T);
	while(T--){
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",x+i);
		if(n==1){puts("0");continue;}
		if(cs==11||cs==12){
			long long D=x[2]-x[1],o=d/D;
			if(o<2)puts("0");
			else printf("%d\n",(int)max((n-1)-(o*2-1)+1,0ll));
			continue;
		}
		int res=0;
		for(int _=1;_<=n;_++){
			dp[_]=0,num[_]=1,cnt[1]=1,a[_]=1,b[_]=1,p=_;
			for(int i=_+1;i<=n;i++){
				while(p<i&&x[i]-x[p]>d)cnt[a[p]]-=b[p],p++;
				dp[i]=dp[i-1];
				while(!cnt[dp[i]])dp[i]++;
				num[i]=cnt[dp[i]];
				a[i]=dp[i]+1;
				b[i]=num[i];
				cnt[a[i]]+=b[i];
			}
			for(int i=p;i<=n;i++)cnt[a[i]]-=b[i];
			for(int i=_;i<=n;i++)if(num[i]==2)res++;
		}
		printf("%d\n",res);
	}
}