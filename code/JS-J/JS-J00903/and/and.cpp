#include <bits/stdc++.h>
using namespace std;
long long  w[20005], ww[20005];
long long cnt = 1;
int n, m;
//int q(int a){
//    int q1, q2;
//    if(a > 3){
//        return q(2) & q(a - 2);
//    }
//    if(a == 2){
//        for(int i = 1; i < n ;i++){
//            for(int j = i; j <= n; j++){
//                //cout << i << " " << j << endl;
//                if(ww[i] && w[j]){
//                    int cnt1 = w[i] & w[j];
//                    if(cnt1 > cnt){
//                        q1 = i;q2 = j;
//                        cnt = cnt1;
//                    }
//                }
//            }
//        }
//        ww[q1] = 0;
//        ww[q2] = 0;
//        return cnt;
//    }
//    if(cnt == 1){
//        return w[n];
//    }
//}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        ww[i] = 1;
    }
    sort(w + 1, w + n + 1);
    if(m == 1){
        cout << w[n];
        return 0;
    }else if(m == n){
        cnt = w[1];
        for(int i = 1; i <= n; i++){
            cnt &= w[i];
        }
        cout << cnt;
        return 0;
    }else if(m == 2){
        for(int i = 1; i < n ;i++){
            for(int j = i; j <= n; j++){
                //cout << i << " " << j << endl;
                int cnt1 = w[i] & w[j];
                if(cnt1 > cnt) cnt = cnt1;
            }
        }
        cout << cnt;
        return 0;
    }else if(m == n - 1){
        for(int i = 1; i <= n; i++){
            int cnt1 = w[1];
            for(int j = i; j <= n; j++){
                if(i == j) continue;
                cnt1 &= w[i];
            }
            if(cnt1 > cnt) cnt = cnt1;
        }
        cout << cnt;
        return 0;
    }
    if(w[1] == w[n + 1]){
        cout << w[1];
        return 0;
    }
    cnt = pow(2,64) - 1;
    for(int i = n; i >= n - m + 1; i--){
        cnt &= w[i];
        //cout << w[i] << " ";
    }
    cout << cnt;
    return 0;
}
