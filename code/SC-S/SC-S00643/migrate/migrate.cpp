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
const int maxn=2e6+20;
ll fw,T,n,d,a[maxn],nxt[maxn],vis[maxn];
inline void solve(int t){
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	
	for(int i=1;i<=n;i++){
		nxt[i]=nxt[i-1];
		while(nxt[i]<n&&a[nxt[i]+1]-a[i]<=d) nxt[i]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll now=nxt[i],chk=0,las=-1;
		while(now<n){//(now,nxt_now]
			if(now==nxt[now]||chk>1) break;
			if(chk==0) ans+=nxt[now-1]-max({now,nxt[now-2],las==-1?0:nxt[las]});
			if(chk==1) ans+=nxt[now]-nxt[now-1];
			chk+=(nxt[now-1]==nxt[now])+(now-2>=i&&nxt[now-2]==nxt[now]);
			las=nxt[now-1],now=nxt[now];
		}
	}
	printf("%lld\n",ans);
}
bool mbt;
int main(){
//	cerr<<(&mbs-&mbt)/1024.0/1024.0<<endl;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	fw=read(),T=read();
	for(int i=1;i<=T;i++) solve(i); 
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/