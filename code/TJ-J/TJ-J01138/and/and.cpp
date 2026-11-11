#include <bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x > y;
}
long long n,m;
long long a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long sum = a[1];
	for (long long i = 2;i <= m;i++){
		sum = (sum & a[i]);
	}
	cout << sum;
	return 0;
}
