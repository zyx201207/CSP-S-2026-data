#include<bits/stdc++.h>
using namespace std;
long long n , m;
long long a[1000000];
bool cmp(int a , int b){
	return a > b;
}
int cnt(int x){
	int ans = 1;
	int t = m;
	for(int i = 1 ; i <= n - x ; i++){
		if(t >= a[x] - a[x + i]){
			t -= (a[x] - a[x + i]);
			ans++;
		}
		else{
			break;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	int flag = 0;
	cin >> a[1];
	for(int i = 2 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] != a[1]){
			flag = 1;
		}
	}
	if(flag == 0){
		cout << n << endl;
		return 0;
	}
	sort(a + 1 , a + n + 1 , cmp);
	long long maxx = 0;
	for(long long i = 1 ; i <= n ; i++){
		if((n - i + 1) <= maxx){
			cout << maxx << endl;
			return 0;
		}
		long long k = cnt(i);
		maxx = max(maxx , k);
	}
	cout << maxx << endl;
	return 0;
}
