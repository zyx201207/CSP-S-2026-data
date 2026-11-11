#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> a >> b;
    for(int i=1;i<=b;i++){
        cin >> c >> d;
        cout << c/d << endl;
    }
    return 0;
}

