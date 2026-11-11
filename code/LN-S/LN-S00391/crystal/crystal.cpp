#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,m;
int a[N],b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    b[1] = a[1];
    for(int i = 2;i <= n;i++){
        b[i] = a[i] + b[i - 1];
    }

    if(m == 0){
        long long ans = 1;
        for(int i = 2;i <= n;i++){
            if(a[i] == a[1]){
                ans++;
            }else{
                break;
            }
        }
        cout << ans;
        return 0;
    }
    if(n == 1){
        cout << 1;
        return 0;
    }
    long long i = 2;
    while(i <= n){
        if((m - (a[i] * i - b[i])) < 0){
            cout << i - 1;
            return 0;
        }else{
            i++;
            if(i - 1 == n){
                cout << i - 1;
                return 0;
            }
        }
    }
    return 0;
}
