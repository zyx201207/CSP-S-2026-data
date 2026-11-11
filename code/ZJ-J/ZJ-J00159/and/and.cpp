#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n, m;
long long a[N];
long long ans;
bool cmp(long long x, long long y){
	return x>y;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}

//	for(int i=1; i<=n; i++){
//		for(int j=i+1; j<=n; j++){
//			ans = a[i]&a[j];
//			if(ans>mx) mx = ans;
//		}
//	}
	
	sort(a+1, a+1+n, cmp);
	//for(int i=1; i<=n; i++) cout << a[i] << " ";
	ans = a[1];
//	cout << ans << endl;
	for(int i=2; i<=m; i++){
		ans = a[i]&ans;
//		cout << a[i] << endl;
	}
	
	cout << ans; 
	return 0;
}
