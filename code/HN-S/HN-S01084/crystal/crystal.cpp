#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int N=5e5+10;
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),m=read(),ans=1;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;// r must can be choose
		while(l<r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])>m) l=mid+1;
			else r=mid; 
		}
		ans=max(ans,i-r+1);
	}
	cout <<ans;
	return 0;
}
/*
be done on 14:47
*/