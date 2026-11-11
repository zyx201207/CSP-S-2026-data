#include<bits/stdc++.h>
using namespace std;
int w[10000];
int a[10000];
int o[10000];
int l[10000];
int r[10000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    int T;
    for(int i = 1;i <= m;i ++) cin >> w[i];
    for(int i = 1;i <= n;i ++){
        cin >> o[i];
        for(int j = 1;j <= 2 * o[i];j ++){
            if(j == 2) cin >> T;
            if(j % 2 == 1) cin >> a[j];
        }
    }
    for(int i = 1;i <= q;i ++){
        if(i % 2 == 1) cin >> l[i];
        else cin >> r[i];
    }
    for(int i = 1;i <= q;i ++){
        int sum = 0;
        sum += w[l[i]];
        bool is_ans = 0;
        for(int j = 1;j <= n;j ++){
            bool is_have = 0;
            for(int k = 1;k <= o[j];k ++){
                if(a[k] == l[i]){
                    is_have = 1;
                    break;
                }
            }
            is_ans = 0;
            if(is_have == 1){
                for(int k = 1;k <= o[j];k ++){
                    if(a[k] == r[i]){
                        sum += 2 * T;
                        sum += w[r[i]];
                        is_ans = 1;
                        break;
                    }
                }
                if(is_ans == 1) break;
                for(int k = j;k <= n;k ++){
                    if(a[j] == a[k]){
                        sum += T * 4;
                        sum += w[r[i]];
                        is_ans = 1;
                        break;
                    }
                }
            }
            if(is_ans == 1) break;
        }
        cout << sum << endl;
    }
    return 0;
}
