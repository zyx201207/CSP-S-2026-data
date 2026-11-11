#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+666;
int read(){
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<1)+(res<<+3)+(c^48);
		c=getchar();
	}
	return res*f;
}
void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
int n,d,pre[N],a[N],g[N],f[N],c1[N],c2[N],ans;
void solve(){
	ans=0;
	memset(pre,0,sizeof(int)*(n+5));
	memset(a,0,sizeof(int)*(n+5));
	memset(f,0,sizeof(int)*(n+5));
	memset(g,0,sizeof(int)*(n+5));
	memset(c1,0,sizeof(int)*(n+5));
	memset(c2,0,sizeof(int)*(n+5));
	n=read();d=read();
	int l=1;
	for(int i=1;i<=n;++i){
		a[i]=read();
		while(a[i]-a[l]>d)++l;
		pre[i]=l;
	}
	for(int i=1,r=1;i<=n;++i){
		while(r<n&&a[r+1]-a[i]<=d)++r;
//		cerr<<i<<":"<<r<<"_"<<pre[i]<<"====";
		int v1=c1[pre[i]]+1,v2=c2[pre[i]];
		ans=(ans+v2);
//		cerr<<i<<","<<v1<<"_"<<v2<<"\n";
		if(i==r)continue;
		if(r-i>=2){
			c1[r]+=v1;
			c2[r-1]+=v1;
			c2[r]+=v2;
		}
		if(r-i==1){
			c1[r]+=v1;
			c2[r]+=v2;
		}
	}
	print(ans);putchar('\n');
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cid=read(),T=read();
	while(T--)solve();
	return 0;
}
