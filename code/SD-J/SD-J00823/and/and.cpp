#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m.,ans;
	int a[100005];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]) ans = a[i];
	}
	cout << ans;
	return 0; 
} 
