#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
long long sz, ans;
string sh;
struct s{
    char ch;
    int cnt;
};
s str[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        long long a;
        char c;
        cin >> a >> c;
        str[i].ch = c;
        str[i].cnt = a;
        sz += a;
    }
    long long l = 1, r = sz, lid = 1, rid = n, tmp = 1;
    while(l < r){
        if(str[lid].ch != str[rid].ch)ans++;
        l++, r--;
        if(sz - r >= str[rid].cnt){
            rid--;
            sz -= str[rid + 1].cnt;
        }
        if(l - tmp >= str[lid].cnt){
            lid++;
            tmp += str[lid - 1].cnt;
        }
    }
    cout << ans;
    return 0;
}
