#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int, int>mp;
struct node{
	int kskbl;
	int zdjd;
}a[300010];
vector<node>vc;
vector<node>vcc;
int n, m;
int cnt[300010];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i].kskbl;
		a[i].zdjd = i;
	}
	cout << n << ' ' << n << ' ' << n;
} 
