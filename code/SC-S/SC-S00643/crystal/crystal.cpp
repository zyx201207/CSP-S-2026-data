#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool mbs;
const int maxn=5e5+20;
ll n,m,a[maxn],ans;
bool mbt;
int main(){
//	cerr<<(&mbs-&mbt)/1024.0/1024.0<<endl;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	ll now=0,x=1,res=0;
	for(int i=1;i<=n;i++){
		if(i!=1) now+=(a[i]-a[i-1])*res;
		res++;
		while(x<i&&now>m) now-=(a[i]-a[x]),res--,x++;
		ans=max(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}