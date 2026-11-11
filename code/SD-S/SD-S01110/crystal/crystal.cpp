#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n;
int m;
int as;
int a[5000005];
bool cmp(int a , int b){
	return a < b;
}
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a + 1 , a + 1 + n , cmp);
	int r = 1;
	int sum = 0;
	for(int l = 1;l <= n;l++){
		while(r < n && (r - l + 1) * (a[r + 1] - a[r]) + sum <= m){
			sum += ((r - l + 1) * (a[r + 1] - a[r]));
			r += 1;
		}
		as = max(as , r - l + 1);
		if(l != r){
			sum -= (a[r] - a[l]);
		}else{
			r += 1;
		}
	}
	cout<<as<<"\n";
	return 0;
}
