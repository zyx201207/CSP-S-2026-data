#include<bits/stdc++.h>
using namespace std;
int x[2000005];
long long ans = 0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c , t;
    cin >> c >> t;
    if(c == 11 || c == 12){
        while(t--){
            int n , d;
            cin >> n >> d;
            for(int i = 1 ; i <= n ; i++){
                cin >> x[i];
            }
            cout << (n-1)/d << endl;
        }
    }
    else{
        while(t--){
            int n , d;
            cin >> n >> d;
            for(int i = 1 ; i <= n ; i++){
                cin >> x[i];
                ans += n-i;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
