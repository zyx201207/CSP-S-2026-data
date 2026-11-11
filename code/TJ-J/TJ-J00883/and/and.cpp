#include <bits/stdc++.h>
using namespace std;
#define long long int
const int N = 2 * 1e5 + 5;
int n,m;
int a[N];
int cmp(int a,int b){
	return a > b;
}
int mx,mx2 = -1;
int jb;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> a[i],mx2 = max(mx2,a[i]);
	if(n == m){
		jb = a[1];
		for(int i = 2;i <= m; i++){
			jb = jb & a[i];
		}
		cout << jb;
		return 0;
	}
	if(m == 1){
		cout << mx2;
		return 0;
	}
	sort(a + 1,a + 1 + n,cmp);
	mx = a[1];
	for(int i = 2;i <= m; i++){
		mx = mx & a[i];
	}
	cout << mx;
	return 0;
}// &
/*
5 3
31 3 1 15 7

4 2
3 15 12 12

3 15
11 1111
1111
0011
0011
10
01
都为1才为1 
*/
