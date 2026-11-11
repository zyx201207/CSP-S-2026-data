#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while ('0'>ch||ch>'9'){
		if (ch=='-') f*=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9'){
		x=(x<<1ll)+(x<<3ll)+ch-'0';
		ch=getchar();
	}return f*x;
}
int n,m,a[maxn],sum[maxn],l=1,res;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;i++){
		while ((i-l+1)*a[i]-(sum[i]-sum[l-1])>m) l++;
		res=max(res,i-l+1);
	}cout<<res;
	return 0;
}
