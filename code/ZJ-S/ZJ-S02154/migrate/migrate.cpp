#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
typedef long long ll;
void fileIO(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
inline ll read(){
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
const int MAX=2e6+11;
int C,n;
ll d,a[MAX],f[MAX],g[MAX],dp[MAX],pd[MAX],ans;
int r[11][11],num[11][11];
void caseA(){
	d=d/(a[2]-a[1]);
	if(d<=1||2*d>n){
		puts("0");
		return ;
	}
	printf("%lld\n",n-2*d+1);
}
bool check(int x,int y,int z){
	return f[x]>=y&&f[y]>=z;
}
void solve(){
	n=read(),d=read();
	rep(i,1,n){
		a[i]=read();
	}
	if(C==11||C==12){
		caseA();
		rep(i,0,n+1){
			a[i]=0;
		}
		return ;
	}
}
int main(){
	fileIO();
	int T;
	C=read(),T=read();
	while(T--){
		solve();
	}
	return 0;
}
