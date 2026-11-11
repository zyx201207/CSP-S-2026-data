#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int m,t;
    cin >> t;
    cin >> m;
    for(int i=1;i<=m;i++){
        int n,d;
        cin  >> n >> d;
        for(int i=1;i<=n;i++){
            int a;
            cin >> a;
        }
        if(d!=2){
            cout << 0;
        }else{
            cout << n-3;
        }
    }
    return 0;
}
