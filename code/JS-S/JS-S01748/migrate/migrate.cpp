#include <bits/stdc++.h>
using namespace std;

long long a[2000001];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        long long n,d,cnt = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        for(int i = 1;i <= n-3;i++){
            if(a[i+3]-a[i] > d && a[i+1]-a[i] <= d && a[i+2]-a[i+1] <= d && a[i+2]-a[i] <= d && a[i+3]-a[i+2] <= d && a[i+3]-a[i+1] <= d){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}


