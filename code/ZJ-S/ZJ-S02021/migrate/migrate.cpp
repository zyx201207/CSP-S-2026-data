#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int n,m;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	puts("ÔÞÃÀOI");
	return 0;
}
