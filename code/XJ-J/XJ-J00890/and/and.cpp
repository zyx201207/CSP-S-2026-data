#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
long long a[10000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	sum = a[n-m+1];
	for(int i = n-m+1;i<=n-1;i++){
		cout << sum and a[i];
		break;
	}
	return 0;
}