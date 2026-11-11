#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;

int n,m;
int a[N];
int pre[N];
int ans=0;

namespace Flower{
	inline int read(){
		int x=0,f=1;char c=getchar();
		while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
		while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
		return x*f;
	}
	
	inline void write(int x){
		if (x<0) {putchar('-');x=-x;}
		if (x>9) write(x/10);
		putchar(x%10+'0');
		return ;
	}
}using namespace Flower;

inline bool check(int l,int r,int x){
	int val=(r-l+1)*x;
	return (val-(pre[r]-pre[l-1]))<=m;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	ans=1;
	for (int i=2;i<=n;i++){
		int l=1,r=i-1,pos=i-1;
		while (l<=r){
			int mid=(l+r)>>1;
			if (check(mid,i-1,a[i]))
				r=mid-1,pos=mid;
			else
				l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}
	write(ans),puts("");
	return 0;
}