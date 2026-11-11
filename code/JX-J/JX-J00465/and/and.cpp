#include<bits/stdc++.h>
using namespace std;
int a[200007], p[200007];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = 1;
    }
    int res = 0;
    for(int j = 30; j >= 0; j--){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if((a[i]&(1<<j)) != 0 && p[i]){
                ans++;
            }
        }
        if(ans >= m){
            res += (1<<j);
            for(int i = 1; i <= n; i++){
                if((a[i]&(1<<j)) == 0){
                    p[i] = 0;
                }
            }
        }
    }
    cout << res;
    return 0;
}
