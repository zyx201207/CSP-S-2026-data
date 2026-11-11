#include<bits/stdc++.h>
#define int long long
#define PII pair< int, int >

using namespace std;

const int N = 5e5 + 5, mod = 998244353;
int n, m, a[N], s[N], daan; 

template< typename T > void read(T &x){x = 0;char ch = getchar();bool f = true;while (ch < '0' || ch > '9'){if (ch == '-') f = !f;ch = getchar();}while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}x = (f ? x : -x);}
template< typename T, typename ... L > void read(T &a, L && ... b){read(a);read(b ...);}
int ksm(int a, int b, int p){int ans = 1;while (b){if (b & 1) ans = ans * a % p;b >>= 1;a = a * a % p;}return ans;}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	read(n, m);
	for (int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		s[i] = s[i-1] + a[i];
		int l = 1, r = i;
		while (l < r){
			int mid = l + r >> 1;
			if (a[i] * (i - mid + 1) - s[i] + s[mid-1] <= m) r = mid;
			else l = mid + 1; 
		}
		daan = max(daan, i - l + 1);
	}
	printf("%lld", daan);
	return 0;
}
/*
窗外的天气 
就像是 你多变的表情 
下雨了 雨陪我哭泣 
看不清，我也不想看清 
离开你我安静的抽离 
不忍揭晓的剧情 
我的爱留在心里 
学会放弃 
听雨的声音 
一滴滴清晰 

坏了后面忘了 
不过这个第一题怎么比前几年还简单 
*/
