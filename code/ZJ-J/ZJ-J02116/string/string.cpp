#include <bits/stdc++.h>
using namespace std;
long long n , L=0 , l[100001] , r[1000001] , o;
long long sum = 0;
char a[1000001];
int main(){
	freopen ("string.in" , "r" , stdin );
	freopen ("string.out" , "w" , stdout );
	cin >> n;
	for ( int i = 1; i<= n; i++ ){
		cin >> o >> a[i];
		L += o;
		r[i] = r[i-1] + o;
		l[i] = r[i-1] +1;
		
	}for ( int i = 1; i <= n; i++ ){
		int lx = lower_bound(l+1 , l+n+1 , L+1-r[i]) - l;
		int rx = lower_bound(r+1 , r+n+1 , L+1-l[i]) - r;
		if ( L+1-r[i] < l[lx] )	lx--;
		for ( int j = lx; j <= rx; j++ ){
			if ( a[i] != a[j] ){
				sum += r[j] - l[j] + 1;
			}
		}if ( L+1-r[i] > l[lx] && a[i] != a[lx] ){
			sum -= L+1-r[i] - l[lx];
		}if ( r[rx] > L+1-l[i] && a[i] != a[rx] ){
			sum -= r[rx] - (L+1-l[i]);
		}
	}if ( sum < 0 )	cout << 0 << '\n';
	else cout << sum / 2 << '\n';
	return 0;
}