#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 5E5+5;
const int M = 3E5+5;
int n, m, a[N], mp[M], ls[M];
bool check1() {
    for(int i=1;i<n;i++) {
        if(a[i+1] < a[i]) return false;
    }return true;
}
signed main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    if(check1()) {
        for(int i=n;i>=1;i--) {
            if(mp[a[i]] == 0) {
                mp[a[i]] = i;
            }
        }
        for(int i=1;i<=m;i++) cout << mp[i] << ' ';
        return 0;
    }
    reverse(a+1,a+n+1);
    vector<pii> v;
    for(int i=1;i<=n;i++) {
        if(ls[a[i]] != 0) {
            v.push_back(make_pair(ls[a[i]]+1, i));
        }
        ls[a[i]] = i;
    }
    int len = v.size();
    for(int i=1;i<=n;i++) {
        int k;
        for(k=len-1;k>=0;k--) {
            if(v[k].first <= i && v[k].second <= i) {
                break;
            }
        }
        int j=i;
        while(j >= 1) {
            while(k >= 0 && j == v[k].second) {
                j = v[k].first - 1;
                k -- ;
                while(k >= 0 && v[k].second > j) k -- ;
            }
            mp[a[j]] ++ ;
            j -- ;
        }
    }
    mp[a[1]] = n;
    for(int i=1;i<=m;i++) cout << mp[i] << ' ';
    return 0;
}