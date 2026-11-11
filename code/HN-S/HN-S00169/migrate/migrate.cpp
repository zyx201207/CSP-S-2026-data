#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int N=5005,N1=2e+6+5;
const long long INF=2e+17;
int n;
long long d,x[N1],f[N],cnt[N];

void init(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
}

long long DP(int st){
	long long ans=0;
	int sk[N],co[N],l=1,r=1;
	for(int i=1;i<=n;i++) co[i]=0;
	for(int i=st+1;i<=n;i++){f[i]=INF; cnt[i]=0;}
	sk[1]=st; co[0]=1; f[st]=0; cnt[st]=1;
	for(int i=st+1;i<=n;i++){
		while (l<=r && x[i]-x[sk[l]]>d){co[f[sk[l]]]-=cnt[sk[l]]; l++;}
		if(l>r) break;
		f[i]=f[sk[l]]+1; cnt[i]=co[f[sk[l]]];
		if(cnt[i]==2) ans++;
		co[f[i]]+=cnt[i]; sk[++r]=i;
	}
	return ans;
}

void calc1(){
	long long ans=0;
	for(int st=1;st<=n;st++) ans+=DP(st);
	printf("%lld\n",ans);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while (T--){
		init();
		if(c<=10) calc1();
	}
	return 0;
}
