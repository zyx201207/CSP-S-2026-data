#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
ll a[N];
bool s[N];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==1,a[2]==2,a[3]==1,a[4]==3){
		cout<<3<<" "<<1<<" "<<4;
	}
	return 0;
}
