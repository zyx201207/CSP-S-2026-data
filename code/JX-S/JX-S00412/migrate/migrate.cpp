#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll c,t,n,d,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> c;
    for(cin >> t;t;t--){
        cin >> n >> d;
        ll gc = 0;
        bool b = true;
        for(ll i = 1;i <= n;i++){
            cin >> x[i];
            if(i == 2){
                gc = x[2] - x[1];
            }
            else if(i > 2){
                if(x[i] - x[i-1] == gc)
                    b = true;
                else
                    b = false;
            }
        }
        if(b){
            if(gc > d){
                cout << 0 << endl;
            }
            else{
                cout << n-3 << endl;
            }
        }
        else{
            cout << 0 << endl;
        }
        
    }
    return 0;
}