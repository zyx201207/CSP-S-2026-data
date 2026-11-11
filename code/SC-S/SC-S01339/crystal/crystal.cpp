#include <bits/stdc++.h>
#define int long long
#define inf (int)1e18
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
//#define i128 __int128_t
const int N = 5e5 + 5, LOG = 20;
int n, m, a[N], pre[N];
//int st[N][LOG], lg[N];
//void build(){
//    lg[1] = 0;
//    for(int i = 2;i <= n;i ++)lg[i] = lg[i >> 1] + 1;
//    for(int i = 1;i <= n;i ++)st[i][0] = a[i];
//    for(int j = 1;(1LL << j) <= n;j ++){
//        for(int i = 1;i + (1LL << j) - 1 <= n;i ++){
//            st[i][j] = max(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);
//        }
//    }
//}
//int query(int l, int r){
//    int k = lg[r - l + 1];
//    return max(st[l][k], st[r - (1LL << k) + 1][k]);
//}
bool ck(int len){
//    i128 res = 0;
    for(int i = 1;i + len - 1 <= n;i ++){
        int j = i + len - 1;
        int sm = pre[j] - pre[i - 1];
//        int mx = query(i, j);
		int mx = a[j];
		if(mx * len - sm <= m)return true;
    }
    return false;
}
signed main(){
//    freopen("data.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
	sort(a + 1, a + n + 1);
//    build();
    for(int i = 1;i <= n;i ++)pre[i] = pre[i - 1] + a[i];
//	cout << query(1, 3) << " " << query(1, 5) << "\n";
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(ck(mid))l = mid + 1;
        else r = mid - 1;
    }
    cout << r << "\n";
    return 0;
}
// g++ std.cpp -o -O2 std