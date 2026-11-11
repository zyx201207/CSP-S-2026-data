#include<bits/stdc++.h>
using namespace std;
static inline long long read(){
	char c;long long a=0;bool f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=0;
	do a=a*10+(c^48);while(isdigit(c=getchar()));
	return f?a:-a;
}
int n;
long long d;
long long x[2000010];
int bd[2000010];
int lb[2000010];
int rb[2000010];
long long dp1[2000010];
long long sum[2000010];
long long dp2[2000010];
void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;++i)x[i]=read(),bd[i]=lb[i]=rb[i]=dp1[i]=dp2[i]=0;
	int b=n;
	for(int i=n;i;--i){
		while(x[b]-x[i]>d)--b;
		bd[i]=b;
	}
	for(int i=1;i<=n;++i){
		if(!lb[bd[i]])lb[bd[i]]=i;
		rb[bd[i]]=i;
	}
	for(int i=1;i<=n;++i)if(!lb[i])lb[i]=rb[i-1]+1,rb[i]=rb[i-1];
	long long ans=0;
	for(int i=1;i<=n;++i){
		if(rb[i]==i)--rb[i];
		if(lb[i]<=rb[i]){
			dp1[i]=sum[rb[i]]-sum[lb[i]-1]+rb[i]-lb[i]+1;
			dp2[i]=dp2[lb[i]];
		}
		if(lb[i]<rb[i]){
			dp2[i]+=rb[lb[i]+1]-lb[lb[i]+1]+1;
			if(lb[lb[i]]==lb[lb[i]+1]&&rb[lb[i]+1]>=lb[lb[i]])dp2[i]+=dp1[lb[lb[i]]];
		}
		else if(lb[i]+1<i){
			ans+=rb[lb[i]+1]-lb[lb[i]+1]+1;
			if(lb[lb[i]]==lb[lb[i]+1]&&rb[lb[i]+1]>=lb[lb[i]])ans+=dp1[lb[lb[i]]];
		}
		ans+=dp2[i];
		sum[i]=sum[i-1]+dp1[i];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t=(read(),read());
	while(t--)solve();
	return 0;
}
