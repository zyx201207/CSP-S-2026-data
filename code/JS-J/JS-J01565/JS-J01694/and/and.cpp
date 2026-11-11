#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

int n, m, cnt;
ll b, ans;
ll po[33];
bool f = 1;
bool a[N][33];
bool flag[N];

void fe(int c, int j){
    ll val = 1;
    for(int i = 0;i <= 30 && c;i++){
        if(c % 2) a[j][i] = 1;
        c /= 2;
    }
}

void init(){
    po[0] = 1;
    for(int i = 1;i < 31;i++){
        po[i] = po[i - 1] * 2;
    }
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> b;
        fe(b, i);
    }

    for(int i = 30;i > -1;i--){
        cnt = 0;
        for(int j = 1;j <= n;j++){
            if(!flag[j] && a[j][i]){
                cnt++;
            }
        }

        if(cnt >= m){
            ans += po[i];
            for(int j = 1;j <= n;j++){
                if(!a[j][i]){
                    flag[j] = 1;
                }
            }
        }
    }

    cout << ans;
    return 0;
}
