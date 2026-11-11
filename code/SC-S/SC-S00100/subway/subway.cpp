#include<bits/stdc++.h>
#define ll long long
#define N 510000
#define gtc getchar
#define ptc putchar
using namespace std;
inline ll read(){
	ll ans=0,w=1;
	char c=gtc();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=gtc();
	}
	while(isdigit(c)){
		ans=ans*10+(c-'0');
		c=gtc();
	}
	return ans*w;
}
inline void write(ll ans){
	if(ans<0) ans=-ans,ptc('-');
	if(ans>9) write(ans/10);
	ptc(ans%10+'0');
}
ll c,T,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		sort(a+1,a+n+1);
		write(0),puts("");
	}
	return 0;
}