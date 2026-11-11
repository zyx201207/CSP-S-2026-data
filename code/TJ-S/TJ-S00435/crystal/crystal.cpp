#include<bits/stdc++.h>
using namespace std;
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
#define fi first
#define se second
#define mkp make_pair
#define il inline
#define chmax(x,y) ((x<y)&&(x=y))
#define chmin(x,y) ((x>y)&&(x=y))
using pii=pair<int,int>;
typedef long long ll;
template<typename T>il T& read(T &s){
	s=0;int c=gc(),fg=0;while(!isdigit(c))fg|=(c=='-'),c=gc();
	while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=gc();(fg&&(s=-s));return s;
}
template<typename T>il void write(T s){
	if(s<0)pc('-'),s=-s;if(s>9)write(s/10);pc((s%10)^48);
}
constexpr int N=5e5+5;
int n;ll a[N],sum[N],m;
void solve(int){
	read(n);read(m);
//	cin>>n>>m;
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int l=1,r=1;r<=n;r++){
		while(l<r&&a[r]*(r-l+1)-(sum[r]-sum[l-1])>m)l++;
		chmax(ans,r-l+1);
	}
	write(ans);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	signed T=1,cid=0;
//	read(T);
	while(T--){
		solve(cid);
	}
	return 0;
}
