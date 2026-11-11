#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
} 
const int N=2e6+5;

int n,d;
int a[N];
int nxt[N],lst[N];
int n2[N],l2[N];
int ctl[N],ctr[N];
int f[N],g[N];

int solve(){
	n=read(),d=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		nxt[i]=lst[i]=0;
		ctl[i]=ctr[i]=0;
		f[i]=g[i]=0;
	}
	for(int i=1,l=1;i<=n;i++){
		while(l<i&&a[i]-a[l]>d)l++;
		if(l<i){
			lst[i]=l;
			ctr[l]++;
		}
	}
	for(int i=n,r=n;i>=1;i--){
		while(r>i&&a[r]-a[i]>d)r--;
		if(r>i){
			nxt[i]=r;
			ctl[r]++;
		}
	}
//	for(int i=1;i<=n;i++)printf("%lld ",ctl[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%lld ",ctr[i]);puts("");
	for(int i=1;i<=n;i++)n2[i]=nxt[i],l2[i]=lst[i];
	for(int i=1;i<n;i++)
		if(lst[i]&&a[i+1]-a[lst[i]]<=d)
			lst[i]=0;
	for(int i=2;i<=n;i++)
		if(nxt[i]&&a[nxt[i]]-a[i-1]<=d)
			nxt[i]=0;
//	for(int i=1;i<=n;i++)printf("%lld ",lst[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%lld ",nxt[i]);puts("");
	for(int i=1;i<=n;i++){
		if(!lst[i])f[i]=ctl[i];
		else f[i]=f[lst[i]]+ctl[i];
	}
	for(int i=n;i>=1;i--){
		if(!nxt[i])g[i]=ctr[i];
		else g[i]=g[nxt[i]]+ctr[i];
	}
//	for(int i=1;i<=n;i++)printf("%lld ",f[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%lld ",g[i]);puts("");
	int res=0;
	for(int i=1;i<n;i++){
		if(!lst[i+1]||!nxt[i]||
			lst[i+1]==i||nxt[i]==i+1)
				continue;
		int lv,rv;
		if(l2[i]==l2[i+1])lv=f[i+1];
		else lv=ctl[i+1];
		if(n2[i]==n2[i+1])rv=g[i];
		else rv=ctr[i];
		res+=lv*rv;
	}
	return res;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	read();int T=read();
	while(T--){
		printf("%lld\n",solve());
	}
	
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1 1
6 3
0 1 2 3 4 7

1 1
6 4
-3 0 1 2 3 4


1 1
10 22
0 7 14 21 28 35 42 49 56 63

1 1
5 3
-3 0 2 3 4

2


*/
