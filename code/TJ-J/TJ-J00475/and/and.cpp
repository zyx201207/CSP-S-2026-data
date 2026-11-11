#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200004];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int p=a[n];
	for (int i=n-1;i>=n-m;i--){
		p=p&a[i];
	}
	cout << p;
}
