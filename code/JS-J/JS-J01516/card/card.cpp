#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], sum[500005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(n == m){
        for(int i = 1;i <= n;i++){
            sum[a[i]] = (n - i + 1) * (n - i + 2) / 2;
        }
        for(int i = 1;i <= n;i++){
            cout << sum[i] << " ";
        }
    }
    else{
        for(int i = 1;i <= n;i++){
            sum[a[i]] += n - i + 1;
        }
        for(int i = 1;i <= m;i++){
            cout << sum[i] << " ";
        }
    }
    return 0;
}
