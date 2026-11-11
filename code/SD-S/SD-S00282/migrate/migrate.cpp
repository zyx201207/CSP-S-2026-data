#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
#define ptc putchar
#define gtc getchar
using namespace std;
ll read(){
	ll x=0,f=1; char ch=gtc();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=gtc(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gtc();
	return x*f;
}
void write(ll x){
	if(x<0) ptc('-'),x=-x;
	if(x>9) write(x/10);
	ptc(x%10+'0');
}
inline void printsp(ll x){ write(x),ptc(' '); }
inline void println(ll x){ write(x),ptc('\n'); }
const int maxn=2e6+5;
int c,T,n,dir[maxn],f[maxn],g[maxn],lst[maxn],nxt[maxn],pre[maxn];
ll x[maxn],d;
void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1,j=1;i<=n;i++){
		while(j<n&&x[j+1]-x[i]<=d) j++;
		dir[i]=j;
		if(j==i) j++;
	}
//	for(int i=1;i<=n;i++) cout<<dir[i]<<" ";
//	cout<<"\n"; 
//	if(x[n]-x[1]<=10*d){
//		ll ans=0;
//		for(int i=n;i>=1;i--){
//			if(i==n||dir[i+1]!=dir[i]) nxt[i]=i;
//			else nxt[i]=nxt[i+1];
//		}
//		for(int i=1,j=1;i<=n;i++){
//			while(j<i&&dir[j]<i+1) j++;
//			pre[i]=j; 
//		}
//		for(int r=1;r<=n;r++){
//			int now=r,q1=0,q2=-1;
//			if(dir[now-1]<r) continue;
//			now--;
//			while(now!=0){
//				int pl=pre[now],nq1=-1,nq2=-1;
//				if(dir[pl]==now+1){
//					if(q1==1){
//						ans+=nxt[pl]-pl+1;
//						nq1=1;
//						if(nxt[pl]>=pl+1) nq2=1;
//					}
//				}
//				if(q1==0&&q2==0){
//					int fl,fr;
//					if(dir[pl]==now+1) fl=nxt[pl]+1;
//					else fl=pl;
//					fr=nxt[fl];
//					if(fl<=now&&dir[fl]==now+2){
//						ans+=(fr-fl+1);
//						if(fl<=pl&&pl<=fr) nq1=1;
//						else if(fl<=pl+1&&pl+1<=fr) nq2=1;
//					}
//				}
//				q1=nq1,q2=nq2;
//				now=pre[now]-1;
//			}
//		}
//		return 0;
//	}
	ll ans=0;
	for(int r=1;r<=n;r++){
		for(int i=0;i<=n+1;i++) f[i]=g[i]=lst[i]=0;
		f[r]=g[r]=0,lst[0]=r;
		for(int l=r-1;l>=1;l--){
			if(dir[l]==l) break;
			int arv=min(dir[l],r),pos=lst[g[arv]];
			g[l]=g[arv]+1;
//			cout<<g[l]<<" "<<arv<<" "<<pos<<"\n";
			if(pos==arv){//¶¼
				if(f[arv]==1) ans++,f[l]=1;
				else f[l]=f[arv];
			}else if(pos==arv-1){
				if(f[arv]==0&&f[pos]==0) ans++,f[l]=1;
				else f[l]=-1;
			}else{
				f[l]=-1;
			}
//			cout<<f[l]<<"\n";
			lst[g[l]]=l;
		}
	}
	println(ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--) solve();
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/
