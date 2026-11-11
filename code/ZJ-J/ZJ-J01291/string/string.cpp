#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+5;

int n, a[N];
char c[N];

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++)cin>>a[i]>>c[i];
	
	int cnt = 0;	
	for(int i = 1, j = n; i <= j; ){
		if(a[i] < a[j])cnt += (c[i] == c[j] ? 0 : a[i]), a[j] -= a[i], i++;
		else if(a[i] > a[j])cnt += (c[i] == c[j] ? 0 : a[j]), a[i] -= a[j], j--;
		else if(a[i] == a[j])cnt += (c[i] == c[j] ? 0 : a[i]), i++, j--; 
	}
	cout<<cnt;
	return 0;
}

