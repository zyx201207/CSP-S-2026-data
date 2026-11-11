#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node{
    char c;
    long long l, r;
}a[N];
bool flag = 1;
int n;
void solve(int cnt){
    long long ans = 0, last = 0;
    for(int i = 1;i <= cnt / 2;i++){
        if(a[i].c == a[cnt - i + 1].c){
            long long l = a[i].l, r = a[i].r;
            long long ll = a[cnt - i + 1].l, rr = a[cnt - i + 1].r;
            if(r - l < rr - ll + last){
                ans += (rr - ll + last + l - r);
                last = -(rr - ll + last + l - r);
            }else if(r - l > rr - ll + last){
                ans += abs(rr - ll + last + l - r);
                last = rr - ll + last + l - r;
            }
        }else{
            long long l = a[i].l, r = a[i].r;
            long long ll = a[cnt - i + 1].l, rr = a[cnt - i + 1].r;
            ans += min(ll - l, rr - r);
            if(r - l < rr - ll + last){
                ans += (rr - ll + last + l - r);
                last = -(rr - ll + last + l - r);
            }else if(r - l > rr - ll + last){
                ans += abs(rr - ll + last + l - r);
                last = rr - ll + last + l - r;
            }
        }
    }
    cout << ans << '\n';
}
void solve1(){
    string s = "";
    int cnt = n;
    for(int i = 1;i <= n;i++){
        long long x;
        char c;
        cin >> x >> c;
        if(a[i].c == a[i - 1].c){
            a[i - 1].r = a[i - 1].r + x;
            cnt--;
            i--;
            n--;
        }else{
            a[i].r = a[i - 1].r + x;
        }
        a[i].c = c;
        a[i].l = a[i - 1].r;
        if(x <= 500){
            for(int j = 1;j <= x;j++){
                s += c;
            }
        }else{
            flag = 0;
        }
    }
    if(!flag){
        solve(cnt);
        return;
    }
    long long ans = 0;
    for(int i = 0;i <= s.size() / 2;i++){
        if(s[i] != s[s.size() - i - 1]){
            ans++;
        }
    }
    cout << ans << '\n';
}
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    solve1();
    return 0;
}
