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

const int N=2e6+10;

int x[N];
int n,d;
void solve(){
	input(n);
	input(d);
	for(int i=1;i<=n;i++) input(x[i]);
	if(d<2*(x[2]-x[1])) print(0);
	else print(n-3);
	putchar('\n');
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	input(C);
	input(T);
	while(T--) solve();
}