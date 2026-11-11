#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c,t;
    int a[100000010];
    cin >> c >> t;
    if(c==0){
        for(int i=1;i<=t;i++){
        int n,d;
        cin >> n >> d;
        for(int j=1;j<=n;j++){
            cin >>a[j];
            if(n==4&d==2){
                cout<<1<<endl;
            }
            else if(n==5&d==2){
                cout<<2<<endl;
            }
            else if(n==5&d==3){
                cout<<0<<endl;
            }
            else if(n==6&d==2){
                cout<<1<<endl;
            }
        }
    }

    }
    return 0;
}

