// 10:23 6/6 100pts
#include <iostream>
using namespace std;
#define int long long
#define endl '\n'
int n;
struct qw
{
    int cnt;
    char raw;
}a[200010];
int ck[200010], cnt;
int ans;
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].cnt >> a[i].raw;
        cnt += a[i].cnt;
    }
    int l = 1, r = n;

    for(; l <= n; l++){
        while(a[l].cnt > 0){
            if(l != r){
                int tmp = min(a[l].cnt, a[r].cnt);
                a[l].cnt -= tmp;
                a[r].cnt -= tmp;
                if(a[l].raw != a[r].raw)
                    ans += tmp;
                if(a[r].cnt == 0)
                    r--;
            }
            else    
                a[r].cnt = 0;
        }
        if(a[r].cnt <= 0)
            break;
    }
    cout << ans;
}
// never gonna let you down
/*
//freopen("string.in", "r", stdin);
// freopen("string.in", "r", stdin);
freopen("string1.in", "r", stdin);
freopen("string.in", "w", stdin);
freopen("string.in", "r", stdout);
freopen("string.in", "w", stdout);

//freopen("string.out", "w", stdout);
// freopen("string.out", "w", stdout);
freopen("string1.out", "r", stdin);
freopen("string.out", "w", stdin);
freopen("string.out", "r", stdout);
freopen("string.out", "w", stdout);
freopen("string.ans", "w", stdout);
*/