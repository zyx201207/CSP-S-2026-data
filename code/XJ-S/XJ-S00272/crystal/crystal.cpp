#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n , m , a[N] , b[N];
bool chk(int num){
	for(int i = num;i <= n;i++){
		if(a[i] * num - (b[i] - b[i - num]) <= m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1;i <= n;i++){
		b[i] = b[i - 1] + a[i]; 
	}
	int l = 1 , r = n + 1;
	while(l + 1 < r){
		int mid = (l + r) / 2;
		if(chk(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
	cout<<l;
}
