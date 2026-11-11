#include <iostream>
using namespace std;
int main(){
    int n, ai[200001], weight = 0, lw = 0, rw = -1, ans = 0, ot = 0;
    char ac[200001];
    freopen("string.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> ai[i] >> ac[i];
        weight += ai[i];
    }
    char left[weight / 2] = {0}, right[weight / 2] = {0};
    if (weight % 2 == 0){
        ot++;}
    for (int i = 0;i < n;i++){
        for (int j = 0;j < ai[i];j++){
            if (lw < weight / 2){
                left[lw] = ac[i];
                lw++;}
            else{
                rw++;
                if (rw > 0 - ot){
                    right[weight / 2 - rw - ot] = ac[i];
                }
                else{continue;}
                }
            }
    }
    for (int i = 0;i<weight/2;i++){
        if (left[i] - 0 != right[i] - 0){
            ans++;
        }
    }
    freopen("string.ans", "w", stdout);
    cout << ans;
    return 0;}
