#include <bits/stdc++.h>
using namespace std;
int a[2000004];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        int n,d;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        int dis = a[2] - a[1];
        if(d < dis){
            cout << '0' << endl;
        }
        else{
            int x = d / dis;
            cout << n - x << endl;
        }
    }
    return 0;
}
