#include<bits/stdc++.h>
#define int long long
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
const int maxn=5e5+5,inf=1e18;
int n,m,a[maxn],pre[maxn];

bool check(int len){
	for(int i=1;i+len-1<=n;i++){
		int mx=a[i+len-1],sum=pre[i+len-1]-pre[i-1];
		if(mx*len-sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,r=n,best;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1,best=mid;
		else r=mid-1;
	}
	println(best);
	return 0;
} 
