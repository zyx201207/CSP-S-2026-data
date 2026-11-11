#include<bits/stdc++.h>
using namespace std;
int c,t;
long long dao[2000010];
long long ans[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >>c >>t;
    for(int i = 1;i <= t;i++){
        int n;
        long long d;
        cin >> n >> d;
        if(d%2==1){
            cout <<"0"<<endl;
            continue;
        }
        for(int j = 1; j<= n;j++){
            cin >> dao[j];
            ans[j] = ans[j-1]+dao[j];
        }
        cout << abs(ans[n])%d<<endl;
    }
    return 0;
}
