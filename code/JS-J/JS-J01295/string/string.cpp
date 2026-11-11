#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e5 + 7;
struct str{
    int x;
    char ch;
}a[N];
int n, id, ans;
char c;
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1, len; i <= n; i++){
        cin >> len;
        cin >> c;
        if(a[id].ch == c){
            a[id].x += len;
        }else{
            id++;
            a[id].x = len;
            a[id].ch = c;
        }
    }
    int lft = 1, rgt = id;
    while(lft < rgt){
        if(a[lft].ch == a[rgt].ch){
            int cha = min(a[lft].x, a[rgt].x);
            a[lft].x -= cha;
            a[rgt].x -= cha;
            if(a[lft].x == 0) lft++;
            if(a[rgt].x == 0) rgt--;
        }else{
            int cha = min(a[lft].x, a[rgt].x);
            a[lft].x -= cha;
            a[rgt].x -= cha;
            ans += cha;
            if(a[lft].x == 0) lft++;
            if(a[rgt].x == 0) rgt--;
        }
    }
    cout << ans << '\n';
    return 0;
}