#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
int C,T,n,nxt[N],pre[N],ans,cnt,c[N],d1[N],d2[N],t[N];
long long x[N],d;

void read(int &x){
	int f=1;
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();	
	}
	while(ch>='0'&&ch<='9') 
		x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=f;
}

int lowbit(int x){
	return x&(-x);
}

void add(int x,int k){
	if(!x) return;
	for(;x<=n;x+=lowbit(x)) c[x]+=k;
}

int query(int x){
	if(!x) return 0;
	int res=0;
	for(;x;x-=lowbit(x)) res+=c[x];
	return res;
}

void solve(){
	ans=0;
	x[0]=LLONG_MIN,x[n+1]=LLONG_MAX;
	pre[1]=0,nxt[n]=n+1;
	for(int i=1;i<=n;++i){
		if(i<n) nxt[i]=upper_bound(x,x+2+n,x[i]+d)-x-1;
		if(i>1) pre[i]=lower_bound(x,x+2+n,x[i]-d)-x;
	}
	for(int i=0;i<=n+1;++i) d1[i]=d2[i]=0;
	for(int i=2;i<=n;++i)
		if(nxt[pre[i]]==i&&pre[i]!=i) d1[i]=d1[pre[i]]+1;
	for(int i=n-1;i>=1;--i)
		if(pre[nxt[i]]==i&&nxt[i]!=i) d2[i]=d2[nxt[i]]+1;
	for(int i=1,l,r;i<n;++i){
		int a=nxt[i],b=nxt[a];
		if(b-a-1>0) ans+=b-a-1;
		if(a==pre[b]||b==n+1||a==b||a==i||pre[b]!=a-1) continue;
		if(pre[pre[b]]!=i){
			++ans;
			continue;
		}
		ans+=(d1[i]+1)*(d2[b]+1);
	}
	printf("%lld\n",ans);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(C),read(T);
	while(T--){
		read(n),read(d);
		for(int i=1;i<=n;++i) read(x[i]);
		solve();
	}
	return 0;
}