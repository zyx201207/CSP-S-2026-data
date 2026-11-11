#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == n){
		int v = a[1];
		for (int i = 1; i <= n; i++){
			v = v&a[i];
		}
		cout << v;
	if(m == 1){
		int v = 0;
		for (int i = 1; i <= n; i++){
			v = max(v,a[i]);
		}
		cout << v;
	}
	if(m == 2){
		int v = 0;
		for (int i = 1; i <= n; i++){
			v = max(v,a[i-1]);
		}
	}
	return 0;
}
}
