#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int n;
long long a[MAXN], b[MAXN], c[MAXN], m;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; i++){
		b[i] = b[i-1] + a[i];
		c[i] = a[i] * i - b[i];
	}
	
	for(int k = 1; k <= n; k++){
		if(c[k] > m){
			cout << k-1;
			break;
		}
	}
	
	return 0;
} 
