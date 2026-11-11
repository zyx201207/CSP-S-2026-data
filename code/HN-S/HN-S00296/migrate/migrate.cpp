#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){int x = 0,zt = 1;char ch = getchar();while(ch<48||ch>57){if(ch==45)zt = -1;ch = getchar();}while(48<=ch&&ch<=57){x = (x<<3)+(x<<1)+(ch^48);ch = getchar();}return x*zt;}
const int N = 2e6 + 10;
int n,m,cnt,ans,C,a[N],rr[N],rsum[N];//ll[N],lsum[N],rrsum[N];
struct A{int l,r;}b[N];
void CX(){
	n = read();m = read();cnt = ans = 0;
	for(int i=1;i<=n;i++)a[i] = read(),rsum[i] = 0;//lsum[i] = rrsum[i] = 0;
	for(int i=1,j=1;i<=n;i++){
		while(j<=n&&a[j]-a[i]<=m)j++;j--;
		rr[i] = j;
		// if(lsum[i]==-1)lsum[i]++;
		// lsum[i]++;
		// if(!lsum[j])lsum[j] = -1,vv[j] = 1;
		// lsum[j] += lsum[i];
		// cout<<j<<' ';
	}
	// for(int i=n,j=n;i;i--){
	// 	while(j&&a[i]-a[j]<=m)j--;j++;
	// 	ll[i] = j;
	// }
	// cout<<'\n';
	// for(int i=n;i;i--)rsum[i] = (vv[rr[i]]?0:rsum[rr[i]])+1;
	// for(int i=1;i<=n;i++)cout<<lsum[i]<<' '<<rsum[i]<<'\n';
	for(int i=1;i<=n-3;i++){
		int x = rr[i];
		if(x<i+2)continue;
		int y = rr[x-2]+1;
		if(y>n)continue;
		if(rr[x-1]<y)continue;
		b[++cnt] = {i,y};
		// ans += lsum[i]*rsum[y];
		// cout<<i<<' '<<y<<' '<<lsum[i]<<' '<<rsum[y]<<'\n';
	}
	// cout<<cnt<<'\n';
	// cout<<rr[1]<<' '<<rr[rr[1]-2]+1<<'\n';
	// cout<<rr[2]<<' '<<rr[rr[2]-2]+1<<'\n';
	// for(int i=1;i<=cnt;i++)cout<<b[i].l<<' '<<b[i].r<<'\n';
	// ans = 0;
	for(int l=1,r=1,lst=0;r<=n;r++,l=r){
		while(r<n&&a[r+1]-a[r]<=m)r++;
		int x = lst+1;
		while(x<=cnt&&l<=b[x].l&&b[x].l<=r)x++;x--;
		// cout<<l<<' '<<r<<' '<<lst+1<<' '<<x<<'\n';
		for(int i=x;i>lst;i--){
			int ls = b[i].l-b[i-1].l,rs = b[i+1].r-b[i].r;
			if(i==lst+1)ls = b[i].l-l+1;
			if(i==x)rs = r-b[i].r+1;
			else if(b[i].r==b[i+1].r)rs = rsum[i+1];
			rsum[i] = rs;
			// rrsum[b[i].r] = rs;
			// cout<<b[i].l<<' '<<b[i].r<<' '<<ls<<' '<<rs<<'\n';
			ans += ls*rs;
		}
		lst = x;
	}
	// cnt = 0;
	// for(int i=n;i>=4;i--){
	// 	int x = ll[i];
	// 	if(x>i-2)continue;
	// 	int y = ll[x+2]-1;
	// 	if(y<=0)continue;
	// 	if(ll[x+1]>y)continue;
	// 	// cout<<i<<' '<<x<<' '<<y<<'\n';
	// 	b[++cnt] = {y,i};
	// }
	// reverse(b+1,b+cnt+1);
	// for(int l=1,r=1,lst=0;r<=n;r++,l=r){
	// 	while(r<n&&a[r+1]-a[r]<=m)r++;
	// 	int x = lst+1;
	// 	while(x<=cnt&&l<=b[x].l&&b[x].l<=r)x++;x--;
	// 	// cout<<l<<' '<<r<<' '<<lst+1<<' '<<x<<'\n';
	// 	for(int i=lst+1;i<=x;i++){
	// 		int ls = b[i].l-b[i-1].l;
	// 		if(i==lst+1)ls = b[i].l-l+1;
	// 		else if(b[i].l==b[i-1].l)ls = lsum[i-1];
	// 		lsum[b[i].l] = ls;
	// 		// cout<<b[i].l<<' '<<b[i].r<<' '<<ls<<'\n';
	// 	}
	// 	lst = x;
	// }
	// for(int i=1;i<=cnt;i++){
	// 	// cout<<b[i].l<<' '<<b[i].r<<' '<<lsum[b[i].l]<<' '<<rrsum[b[i].r]<<'\n';
	// 	ans += lsum[b[i].l]*rrsum[b[i].r];
	// }
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C = read();int qqq = read();
	while(qqq--)CX();
	return 0;
}