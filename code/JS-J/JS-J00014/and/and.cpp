#include<bits/stdc++.h>
using namespace std;
int n, m, a[200010][32], sum[33];
int ans;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i][1];
    }
    sort(a + 1, a + 1 + n);
    int mark;
    int now = 1;
    while(true){
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; i++){
            int x = a[i][now];
            int f = 1;
            while(x != 0){
                sum[f] += (x % 2);
                x /= 2;
                f++;
            }
        }
        mark = 0;
        for(int i = 32; i >= 1; i--){
            if(sum[i] >= m){
                mark = i;
                break;
            }
        }
        if(mark == 0){
            break;
        }
        int rear = 0;
        for(int i = 1; i <= n; i++){
            if(a[i][now] & (1 << (mark - 1))  == 1){
                rear++;
            }
        }
        now++;
        n = rear;
        ans += (1 << (mark - 1));
    }
    cout << ans;
    return 0;
}
