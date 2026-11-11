#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for(int i = (a);i<=(n);++i)
#define ll long long
#define ill __int128
 
using namespace std;

template<typename T>inline void read(T &x){
	char c = getchar();
	short int t = 1;x = 0;
	for(;!isdigit(c);c = getchar())if(c == '-')t=-1;
	for(;isdigit(c);c = getchar())x = (x<<1) + (x<<3) + (c^48);
	x*=t;
}
template<typename T>inline void write(T x){
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x >= 10){
		write(x/10);
	}
	putchar(x % 10 + '0');
}
const int N = 5e5 + 10;
int n = 0;
ll m = 0;
ll a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	if(m == 0){
		cout <<1<<endl;
		return 0;
	}
	rep(i,1,n){
		read(a[i]);
	}
	
	sort(a+1,a+1+n);
	rep(i,1,n){
		sum[i] = sum[i-1] + a[i];
	}
	int ans = 1;	
	for(int i = 1;i<=n;++i){
		int l = 1,r = i,as = i;
		ill t = (ill)m - (ill)(i+1)*a[i] + sum[i];
		while(l <= r){
			int mid = (l + r) >> 1;
			ill p = -(ill)mid * a[i] + sum[mid-1];
			if(p <= t){
				r = mid-1;
				as = mid;
			}else{
				l = mid + 1;
			}
		}
		ans = max(ans,i - as + 1);		
	}
//	for(int i = 1;i<=n;++i){
//		for(int j = i-1;j>=1;--j){
//			if((ill)(i - j + 1)*a[i] - (sum[i] - sum[j-1]) <= m){
//				ans  = max(ans,i - j + 1);
//			}else{
//				break;
//			}
//		}
//	}
	cout <<ans<<endl;	
	return 0;
}
/*
可以至多做 m 次加一，问你最终元素相同的数量最多是多少。 

对 a 排序，维护后缀和，二分最终相同的元素大小。

二分的里面二分找到最后一个 <= x 的位置 p，这样前 p 位是我们可能取到的答案。

从第 p 个从后往前扫，贪心的考虑这样的答案肯定先满足好满足的。

直到用完了 m。 

考虑证明二分的单调性，当我们要求所有数都等于一个较大的数的时候，显然对于固定的 m，
答案是很难变大的。
感觉这个单调性不太对，我考虑 hack 一下。 

显然当所有数都变成一样的时候，没有必要再变大了。答案上界就是 n。

对于第 i 个数，我们钦定最终取答案的时候取的相等的数是这个。

然后维护一个前缀和。我们要找到一个最大的位置 j,
满足 (j - i + 1)*a[i] - (sum[i] - sum[j-1]) <= m

然后二分。 

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/

