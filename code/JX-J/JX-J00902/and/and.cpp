#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200001] = {}, l[200001] = {}, ans = -1;

void rang(long long rx, long long rp){
    for(int i = rx;i <= n;i++){
        l[rp] = a[i];
        if(rp == m){
            long long nans = l[1];
            for(int i = 2;i <= m;i++){
                nans  = nans & l[i];
            }
            if(nans > ans) ans = nans;
        }
        else{
            rang(i+1, rp+1);
        }
    }
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    rang(1, 1);

    cout << ans;

    return 0;
}

