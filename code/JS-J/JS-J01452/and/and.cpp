#include<bits/stdc++.h>
using namespace std;

long long n = 0, m = 0, ans = 0;
int maxlog = 0;
bool a[200010][40], check[200010];

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        long long x = 0;
        cin >> x;
        int j = 0;
        while(x > 0){
            a[i][j] = x % 2;
            maxlog = max(maxlog, j);
            j++;
            x /= 2;
        }
    }
    for(int i = maxlog;i >= 0;i--){
        int x = 0;
        for(int j = 1;j <= n;j++){
            if(check[j] == false && a[j][i]){
                x++;
            }
        }
        if(x >= m){
            ans += pow(2, i);
            for(int j = 1;j <= n;j++){
                if(check[j] == false && !a[j][i]){
                    check[j] = true;
                }
            }
        }
    }
    cout << ans;
    return 0;
}

//tan xin ?
//YESSSSSSS
