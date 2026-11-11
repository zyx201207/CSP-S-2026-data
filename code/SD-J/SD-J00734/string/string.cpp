#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n , a[N] , st = 1 , ed , sum;
char p[N];
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] >> p[i];
	}
	st = 0; ed = n;
	while(st < ed){
		st++;
		if(st == ed) break;
		while(1){
			int tmp1 = a[st] , tmp2 = a[ed];
			a[ed] -= min(tmp1 , tmp2);
			a[st] -= min(tmp1 , tmp2);
			if(p[st] != p[ed]) sum += min(tmp1 , tmp2);
			if(a[st] == 0) break;
			ed--;
		}
	}
	cout << sum;
	return 0;
}
