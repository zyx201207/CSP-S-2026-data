#include <bits/stdc++.h>
using namespace std;
int a[300005],b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m; cin >> n >> m;
    vector <int> vt;
    for (int i = 0;i < n;i++){
        int x; cin >> x;
        vt.push_back(x);
    }
    for (int i = 0;i < n;i++){
        for (int j = 0;j < 300005;j++){
            a[j] = 0;
        }
        for (int j = 1;j < n;j++){
            a[vt[j]]++;
            if(a[vt[j]] > 1){
                for(int k = j;;k--){
                    if(vt[k] == vt[j]){
                        a[vt[k]]--;
                        break;
                    }
                    a[vt[k]]--;
                }
            }
        }
        for (int j = 0;j < m;j++){
            b[j] += a[j];
        }
    }
    for (int j = 0;j < m;j++){
        cout << b[j] << ' ';
    }
    return 0;
}
