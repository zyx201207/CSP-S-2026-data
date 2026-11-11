#include<bits/stdc++.h>
#define int long long
using namespace std;
char buf[1<<21],*p1,*p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1<<20,stdin),p1 == p2) ? 0 : *p1++)
template <typename T>
inline void read(T& x){
	x = 0;
	int f = 1;
	char ch = gc();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = gc();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = gc();
	}
	x *= f;
}
int n,m;
int a[500010],s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans = 1,lim = 1;
	for(int i = 2; i <= n; i++){
		while(lim <= n && (i - lim + 1) * a[i] - (s[i] - s[lim - 1]) > m) lim++;
		ans = max(ans,i - lim + 1);
	}
	printf("%lld",ans);
	return 0;
} 
