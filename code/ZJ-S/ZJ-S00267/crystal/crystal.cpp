#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template<typename T>
	void input(T &x){
		x=0;
		bool f=0;
		char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}
		if(f) x=-x;
	}
	
	template<typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>=10) print(x/10);
		putchar(x%10+'0');
	}
}

using namespace quick_io;

#define int long long

const int N=5e5+10;

int a[N];
int sum[N];
int n,m;
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	input(n);
	input(m);
	for(int i=1;i<=n;i++) input(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int l=1,r=0;l<=n;l++){
		r=max(l,r);
		while(r+1<=n&&(r+1-l+1)*a[r+1]-(sum[r+1]-sum[l-1])<=m) r++;
		ans=max(ans,r-l+1);
	}
	print(ans);
}