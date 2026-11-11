#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long X = 1e9 + 5;
struct num{
	long long cut;
	char ch;
}a[N];
long long n;
long long mx = 0;
char found(long long x){
	long long cnt = 1;
	while (x > a[cnt].cut){
		x -= a[cnt].cut;
		cnt++;
	}
	return a[cnt].ch;
}
long long change_left(){
	long long ans = 0;
	for (long long i = 1; i <= mx / 2; i++){
		if (found(i) != found(mx + 1 - i)) ans++;
	}
	return ans;
}
long long change_right(){
	long long ans = 0;
	for (long long i = mx; i >= mx / 2 + 1 ; i--){
		if (found(i) != found(mx + 1 - i)) ans++;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++){
		cin >> a[i].cut >> a[i].ch;
		mx += a[i].cut;
	}
	cout << min(change_left(),change_right()); 
	return 0;
}


