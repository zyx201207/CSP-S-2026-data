//when you use deque or vector,
//by OldDriverTree
#include<bits/stdc++.h>
#define range(vec) vec.begin(),vec.end()
#define tup array<int,3>
#define P pair<int,int>
#define int long long
#define mid (l+r>>1)
using namespace std;
const int N=5e5+1;
int n,m,a[N],s[N];

int read() {
	int x=0; bool f=true; char c=0;
	while (!isdigit(c) ) f&=(c!='-'),c=getchar();
	while (isdigit(c) ) x=x*10+(c&15),c=getchar();
	return f?x:-x;
}
bool check(int x) {
	for (int i=x;i<=n;i++)
	if (x*a[i]-s[i]+s[i-x]<=m)
	return true; return false;
}
main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read(); sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while (l<=r) check(mid)?l=mid+1:r=mid-1;
	return !printf("%lld",r);
}
//14:35 Í¨¹ý T1 
