#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int c,t,n,d,a[2000009],ans,L[2000009],R[2000009];
int jumpr(int x){
	return upper_bound(a+1,a+n+1,a[x]+d)-a-1;
}
int jumpl(int x){
	return lower_bound(a+1,a+n+1,a[x]-d)-a;
}
int dis[5009][5009],g[5009][5009];
void work(int l,int r){
	int x=L[r],y=dis[l][x],z=0;
	dis[l][r]=y+1;
	for(int i=x;i<=min(x+2,r)&&dis[l][i]==y;i++)
		z+=g[l][i];
	g[l][r]=z;
	return ;
}
void solve1(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=(i==j);
	for(int len=2;len<=n;len++)
		for(int l=1,r=l+len-1;r<=n;l++,r++){
			work(l,r);
			if (g[l][r]==2) ans++;
		}
	return ;
}
void solve2(){
	int k=d/(a[2]-a[1]);
	if (k<=1) return ;
	ans=max(0ll,n-2*k+1);
	return ;
}
int cntl[2000009];
void solve3(){
	for(int i=1;i<=n;i++) cntl[L[i]]++;
	for(int i=1;i<=n;i++)
		if (R[i]-i>=2)
			ans+=cntl[R[i]-1];
	for(int i=1;i<=n;i++) cntl[i]=0;
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			L[i]=jumpl(i);
			R[i]=jumpr(i);
		}
		if (n<=5000) solve1();
		else if (c==11||c==12) solve2();
		else if (c==13||c==14) solve3();
		else solve3();
//		else if (c>=15&&c<=18) solve4();
		printf("%lld\n",ans);
		ans=0;
		for(int i=1;i<=n;i++) a[i]=L[i]=R[i]=0;
	}
	return 0;
}
