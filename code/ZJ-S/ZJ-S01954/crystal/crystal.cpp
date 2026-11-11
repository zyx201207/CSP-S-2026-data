#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#define mp make_pair
#define fo(i , x , y) for(int i = (x) ; i <= (y) ; i++)
#define go(i , x , y) for(int i = (x) ; i >= (y) ; i--)
#define chkmax(a , b) (a) = max((a) , (b))
#define chkmin(a , b) (a) = min((a) , (b))
#define local
#ifdef local
#define debug(x) cerr << #x" : " << x << ", "
#define debugn(x) cerr << #x" : " << x << "\n"
#define debugs(s) cerr << s
#define debugarr(a , n) cerr << #a" : " << "\n"; fo(i , 1 , n) cerr << a[i]; cerr << "\n"
#elif
#define debug(x) "Chytholly is the happiest girl in the world!"
#define debugn(x) "Elaina"
#define debugs(s) "miku"
#define debugarr(a , n) "n-buna"
#endif
using namespace std;
const int maxn = 5e5;
int n;
long long m , a[maxn + 5] , f[maxn + 5];
bool check(int mid){
	for(int l = 1 , r = mid ; r <= n ; l++ , r++){
		long long val = a[r] * mid - (f[r] - f[l - 1]);
		if(val <= m) return true;
	}
	return false;
}
int main(){
	ios :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	fo(i , 1 , n) cin >> a[i];
	sort(a + 1 , a + 1 + n);
	fo(i , 1 , n) f[i] = a[i] + f[i - 1];
	int l = 1 , r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << "\n";
}