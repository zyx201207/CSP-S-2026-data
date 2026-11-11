#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector <long long> a;
bool ca(long long x){
	for(int i = 0;i < n - x + 1;i++){
		int sum = 0;
		for(int j = i;j < i + x - 1;j++){
			sum += a[i + x - 1] - a[j];
		}
		if(sum <= m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	a.resize(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	long long l = 0,r = n - 1;
	while(l < r){
		long long mid = l + (r - l)/2;
		if(ca(mid))l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}
