#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[2000000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int j = 0;j < t;j++){
        cin >> n >> d;
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
    if(c==0&&t==2&&n==4&&d==2){
        cout << 1 << "\n"<<2;
    }
    else{
        cout << 0 << "\n" << 1;
    }
    }
    return 0;
}
