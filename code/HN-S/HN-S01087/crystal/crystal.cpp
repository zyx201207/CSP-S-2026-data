#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar_unlocked();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar_unlocked();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar_unlocked();
	}
	return x*f;
}
int n,a[500005],sum[500005],k;
inline bool check(int x){
	for(int i=x;i<=n;i++){
		if(x*a[i]-(sum[i]-sum[i-x])<=k) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
