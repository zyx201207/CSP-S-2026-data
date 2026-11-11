#include<bits/stdc++.h>
using namespace std;
const int N = 500009;
long long n,m;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long k = m,ans = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	long long max_n = a[n];
	for(int i = n-1;i >= 1;i--){
		int x = max_n-a[i];
		if(k-x>=0){
			k-=x;
			ans++;
		}
	}
	if(ans+1 >= n){
		cout << n << endl;
	}else{
		cout << ans+1 << endl;
	}
	return 0;
}
