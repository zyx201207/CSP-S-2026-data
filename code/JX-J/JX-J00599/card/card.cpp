#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int a[N],b[N],ans[N];

int main(){

    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        int len = 1;
        for (int j = i; j <= n; j++){
            if(b[len-1]==a[j]){
                continue;
            }
            b[len] = a[j];
            len++;
        }
        for (int j = 1; j <= len; j++){
            for (int k = 1; k <= m; k++){
                if(b[j]==k){
                    ans[k]++;
                }
            }
        }
        memset(b,0,sizeof b);
    }
    for (int i = 1; i <= m; i++){
        cout << ans[i] << ' ';
    }

    return 0;
}
