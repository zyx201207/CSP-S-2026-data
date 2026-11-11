#include<bits/stdc++.h>
using namespace std;
int n, m, sum=0, a[200005] = {0};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	if(m == 1) cout << a[n-1];
	else if(m == n){
		sum = a[0];
		for(int i=1;i<n;i++) sum &= a[i];
		cout << sum << '\n';
	}
	return 0;
} 
