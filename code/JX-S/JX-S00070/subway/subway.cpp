#include <bits/stdc++.h>
using namespace std;

int ni[100005], ans;
stack <int> s1;
struct aaa{
    int tg, v, tonglu;
};

int main(){
    aaa s[100000];
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c, n, m, d, p;
    for(int i = 1; i <= m; i++){
            cin >> mi[i];
    }
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        s[i].tonglu = k;
        for(int j = 1; j <= k; j++){
            cin >> s[i].tg >> s[i].v;
        }
    }
    while(p--){
        ans = 0
        int sty, enl, mx=0;
        cin >> sty >> enl;
        ans += mi[sty], mi[enl];
        for(int i = 1; i <= n; i++){
            int sma = 100000;
            for(int j = 1; j < s[i].tonglu; j++){
                if(sma < s[i].v){
                    sma = s[i].v;
                }
            }
            ans += sma;
        }
        break;
    }
    cout << s;
    return 0;
}
