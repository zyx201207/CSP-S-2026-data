#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;
int n,ans,m,a[maxn],sum[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f^=!(ch^'-'),ch=getchar();
	while( isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*(f-(f^1));
}
bool check(int l,int r){
	int dx=sum[r-1]-sum[l-1],S=a[r]*(r-l);
	if(S-dx<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int now=1;
	for(int i=1;i<=n;i++){
		while(!check(now,i)&&now<i) now++;
		ans=max(ans,i-now+1);
	}
	printf("%lld\n",ans);
	return 0;
}
//14:51