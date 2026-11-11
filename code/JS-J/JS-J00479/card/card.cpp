#include<bits/stdc++.h>
using namespace std;
int a[500010];
int x[300010];
int kx[500010];
int cnt[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    bool b = 1;
    if(m == 1){
        cout << n << " ";
        return 0;
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cnt[a[i]]++;
        if(kx[a[i]] != 0){
            b = 0;
        }
        kx[a[i]]  = 1;
    }
    if(b){
        for(int i = 1;i <= m;i++){
            cout << n << " ";
        }
        return 0;
    }
    for(int i = 1;i <= n;i++){
        cnt[a[i]]--;
        for(int j = 1;j <= m;j++){
            if(a[j]% 2 == 1){
                x[j]++;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << x[i] << " ";
    }
    return 0;
}
