#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e7 + 10;
long long n , m, ans = 0;
long long a[N], p[N];
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out", "w" , stdout);
cin >> n >> m;
for(int i = 1; i <= n; i++){
	cin >> a[i];
}
p[1] = 0;
sort(a, a + n);
for(int i = 1; i <= n; i++){
	p[i] = (i - 1) * (a[i] - a[i - 1]) + p[i - 1];
	if(p[i] <= m){
		ans++;
	}else{
		break;
	}
}

//for(int i = 1; i <= n; i++){
//	if(p[i] <= m){
//		ans++;
//	}
//}
cout << ans << endl;
	return 0;
} 
