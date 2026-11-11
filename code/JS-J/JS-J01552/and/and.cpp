#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    long long sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(i == 1)  sum = a[i];
        else    sum &= a[i];
    }
    if(m == n){
        cout << sum;
    }
    else if(m == 1){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            ans = max(ans,a[i]);
        }
        cout << ans;
    }
    else if(m == 2){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                int num = a[i] & a[j];
                ans = max(ans,num);
            }
        }
        cout << ans;
    }
    else if(m == 3){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                for(int k = j+1;k <= n;k++){
                    int num = a[i] & a[j] & a[k];
                    ans = max(ans,num);
                }
            }
        }
        cout << ans;
    }
    return 0;
}
