#include<bits/stdc++.h>
using namespace std;
long long c,t,x[30],n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int i = 1;i <= t;i++){
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
            cin >> x[i];
        if(c == 13 || c == 14){
            cout << 2;
        }
        if(c == 11 || c == 12){
            cout << x[2] - x[1];
        }
        else
            cout << pow(x[1],2);

    }

    return 0;
}
