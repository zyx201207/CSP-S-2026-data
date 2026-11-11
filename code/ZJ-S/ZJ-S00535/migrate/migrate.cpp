#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e6+8;
int c,t,n;
ll d,x[MAXN];
inline ll read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		ll ans=0;        
		n=read(),d=read();
		for(int i=1;i<=n;i++)x[i]=read();
		sort(x+1,x+n+1);
		if(d==2*(x[2]-x[1]))cout<<max(0,n-3);
		else cout<<0;
		cout<<"\n";
	}
	return 0;
}    