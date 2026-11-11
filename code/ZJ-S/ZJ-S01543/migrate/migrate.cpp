#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,x[2000050],d,an;
void solve1(){
	an=0;
	int f[5050],s[5050],cnt,pv[5050],k;
	for(int i=1;i<=n;i++) pv[i]=0;
	k=1;
	for(int i=1;i<=n;i++){
		while(x[i]-x[k]>d) k++;
		pv[i]=k;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[j]=s[j]=0;
		s[i]=1;
		for(int j=i+1;j<=n;j++){
			f[j]=f[pv[j]]+1;
			s[j]=s[upper_bound(f+i+1,f+j+1,f[pv[j]])-f-1]-s[max(pv[j],i)-1];
			if(s[j]==2) an++;
			s[j]+=s[j-1];
		}
	}
}
void solve2(){
	an=0;
	if(2*(x[2]-x[1])>d) return;
	an=max(0ll,n-d/(x[2]-x[1])*2+1);
}
void solve3(){
	an=0;
}
void solve4(){
	an=0;
}
void solve5(){
	an=0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(c<=10) solve1();
		else if(c<=12) solve2();
		else if(c<=14) solve3();
		else if(c<=18) solve4();
		else solve5();
		printf("%lld\n",an);
	}
	return 0;
}