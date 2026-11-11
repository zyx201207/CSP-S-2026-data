#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5+10;
int n, m;
int a[maxn];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int da = -10;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		da = max(da, a[i]);
	}
	cout << da;
	return 0;
}
