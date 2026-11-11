#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
int n ;
ll m , a[N];
//void solve1(){
//	int ans = 0;
//	sort(a+1,a+1+n);// O nlogn
//	int minn = a[1] , maxx = a[n];
//	for(int i=minn;i<=maxx;i++){// O Amax * n log n
//		int k = 0;
//		for(int j=1;j<=n;j++){
//			if( a[j] <= i)
//				d[k++] = abs(a[j] - i);
//			else
//				break;
//		}
//		if( k == 0)continue;
//		if( k > 0)k --;
//		sort(d,d+k+1);
//		int res = 0 ;
//		ll energy = m;
//		for(int i=0;i<=k;i++){
//			if( energy == 0)break;
//			if( d[i] == 0){
//				res ++;
//				continue;
//			}
//			else{
//				if( energy - d[i] < 0)break;
//				energy -= d[i];
//				res ++;
//			}
//		}
//		ans = max( ans , res);
//	}
//	cout << ans << endl;
//}
//int b[N];
//void solveA(){
//	int res = 0 ;
//	for(int i=1;i<=n;i++){
//		ll sum = i * (i + 1) / 2;
//		if( sum > m){
//			res = i ;
//			break;
//		}
//	}
//	cout << res << endl;
//}
//void solveB(){
//	int res = 1;
//	ll q = a[2] - a[1] , energy = m;
//	for(int i=1;i<=n;i++){
//		ll del = i * q;
//		if( energy < del)break;
//		energy -= del;
//		res ++ ;
//	}
//	if( res > n)res = n;
//	cout << res << endl;
//}
ll di[N] , pre[N] , prev[N];
void solveF(){
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		di[i] = a[i] - a[i-1];
		if( i == 1)di[i] = 0;
		pre[i] = pre[i-1] + di[i];
		prev[i] = prev[i-1] + pre[i];
	} 
	int res = 0;
	int l = 1 , r = 1;
	while( l <= n && r <= n){
		int len = r - l + 1;
		ll dist = 1ll * (len - 1) * pre[r] - (prev[r-1] - prev[l-1]);
		if( m < dist) l ++;
		else{
			res = max( res , len);
			r ++ ;
		}
	}
	cout << res << endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	int su = 0 , sA = 0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
//		if( abs(a[i]) <= 500)su ++;
//		if( a[i] == i)sA ++;
	}	
	solveF();
//	int sB = 1;
//	ll q = a[2] - a[1];
//	for(int i=3;i<=n;i++)
//		if( a[i] - a[i-1] == q)sB ++;
//	if( n <= 5000 && su == n)
//	solve1();
//	else if( sA == n)
//		solveA();
//	else if( sB == n - 1)
//		solveB();
//	else
	fclose(stdin);
	fclose(stdout);
	return 0;
}
