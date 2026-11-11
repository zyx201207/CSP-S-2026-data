#include <bits/stdc++.h>

using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int mxa = -1,mx = -1;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        mxa = max(mxa,a[i]);
    }
    if (m == 1) {
        cout << mxa;
    }
    else if (m == 2){
        for (int i = 1;i <= n - 1;i++){
            for (int j = i + 1;j <= n;j++){
                mx = max(mx,a[i] & a[j]);
            }
        }
    }
    else if (m == 3){
        for (int i = 1;i <= n - 2;i++){
            for (int j = i + 1;j <= n -1;j++){
                for (int k = j + 1;k <= n;k++){
                    mx = max(mx,a[i] & a[j] & a[k]);
                }
            }
        }
    }
    else if (m == 4){
        for (int i = 1;i <= n - 3;i++){
            for (int j = i + 1;j <= n -2;j++){
                for (int k = j + 1;k <= n - 1;k++){
                    for (int l = 1;l <= n;l++){
                        mx = max(mx,a[i] & a[j] & a[k] & a[l]);
                    }
                }
            }
        }
    }
    else if (m == 5){
        for (int i = 1;i <= n - 4;i++){
            for (int j = i + 1;j <= n -3;j++){
                for (int k = j + 1;k <= n - 2;k++){
                    for (int l = 1;l <= n - 1;l++){
                        for (int r = 1;r <= n;r++){
                            mx = max(mx,a[i] & a[j] & a[k] & a[l] & a[r]);
                        }
                    }
                }
            }
        }
    }
    else {
        mx = 511;
    }
    cout <<mx;
    return 0;
}
