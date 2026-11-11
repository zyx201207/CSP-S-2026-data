#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 2000001
int x[maxn];
int f[maxn];
int qz[maxn];
int last[maxn];
int g[maxn];
int c,t,n,d,l,res;
int ans=0;
void solve(){
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	if(n==1){
		printf("0\n");
		return;
	}
	for(int i=1;i<=n;i++){
		f[i]=1;g[i]=0; qz[i]=f[i]; qz[i-1]=0; l=i; last[g[i]]=i;
		for(int j=i+1;j<=n;j++){
			while(x[j]-x[l]>d)l++;
			if(l==j)break;
			f[j]=qz[last[g[l]]]-qz[l-1];
			g[j]=g[l]+1; last[g[j]]=j;
			if(f[j]==2)ans++;
			qz[j]=qz[j-1]+f[j];
		}	
	}
	printf("%lld\n",ans);
	return;
}
void solve2(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	if(n==1){
		printf("0\n");
		return;
	}
	int dis=x[2]-x[1];
	if(d<2*dis){
		printf("0\n");
		return;
	}
	else{
		int sum=d/dis; int gg=0;
		printf("%lld\n",max(gg,n+1-2*sum));
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==11||c==12){
		while(t--)solve2();
	}
	else if(c<=10){
		while(t--)solve();
	}
	else{
		printf("ccf has no eggs.-.-\n");
	}
	return 0;
}