#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int MAX_n = 500010,MAX_m = 300010;
int a[MAX_n],ans[MAX_m];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cout << m; 
	return 0;
}

