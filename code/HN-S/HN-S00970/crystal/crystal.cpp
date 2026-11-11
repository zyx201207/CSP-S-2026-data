#include<bits/stdc++.h>
#define def(i,a,b) for(i32 i = a;i <= b;i ++)
#define udef(i,a,b) for(i32 i = a;i >= b;i --)
#define Max(a,b) (a = max(a,b))
#define Min(a,b) (a = min(a,b))
#define fi first
#define se second
using namespace std;
using i32 = int;
using i63 = long long;
const i63 N = 5e5 + 5,INF = 4e18,mod = 998244353;
i63 n,m,ans; 
i63 a[N],c[N],s[N];
i32 ef(i32 x){
	i32 l = x + 1,r = n;
	while(l <= r){
		i32 md = l + r >> 1;
		if(s[md] - c[x] * (md - x) - s[x] <= m) l = md + 1;
		else r = md - 1; 
	}
	return l - 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin >> n >> m;
	def(i,1,n) {
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n,greater<i32>());
	s[1] = 0;
	def(i,2,n)
		s[i] = a[1] - a[i],c[i] = s[i];
	def(i,2,n) s[i] += s[i - 1]; 
	def(i,1,n){
		i32 l = i;
		i32 r = ef(l);
		Max(ans,r - l + 1ll);
	}
	cout << ans;
	return 0; 
}
/*
看一下 代码与实际用途是否一致 如缩点后应使用缩点后的图b[i]
注意手打hack对拍 然后对症下要特判
谨防RE 队列一定要判非空 一定要判边界 
没事别全开 long long 
该break时别continue
备份备份 别一顿乱搞后该不如之前的 
部分分 部分分 
算一下会不会MLE 
把冗余部分去掉 
15 : 18A
*/ 
