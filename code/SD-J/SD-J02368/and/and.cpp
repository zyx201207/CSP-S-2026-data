#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int a[N];
int main(){
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = n;i<n+1;i++){
		cout << a[i-2];
	}
	return 0;
}
