#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
struct node{
    int cnt;
    char ch;
}a[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i].cnt);
        cin >> a[i].ch;
    }
    ll ans(0);
    int l(0), r = n;
    int lleft(0), rleft = a[n].cnt;
    char nl , nr = a[n].ch;
    while(r-l >= 1){
        //cout << lleft << " " << rleft << endl;
        //cout << nl << " " << nr << endl;
        if(lleft == 0){
            l++;
            lleft = a[l].cnt;
            nl = a[l].ch;
            int x = min(lleft, rleft);
            if(nl != nr){
                ans += x;
            }
            //cout << x << endl;
            lleft -= x;
            rleft -= x;

        }else{
            r--;
            rleft = a[r].cnt;
            nr = a[r].ch;
            int x = min(lleft, rleft);
            if(nl != nr){
                ans += x;
            }
            //cout << x << endl;
            lleft -= x;
            rleft -= x;
        }
    }
    cout << ans;
    return 0;
}
