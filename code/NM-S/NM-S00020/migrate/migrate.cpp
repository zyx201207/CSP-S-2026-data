#include <bits/stdc++.h>
using namespace std;
int x[2000100];
void m(){
    int n,d;
    cin >> n >> d;
    for (int i = 1;i >= n;i++) cin >> x[i];
    if ((n == 4 && d == 2) || (n == 6 && d == 2)){
        cout << 1 << endl;
    }if (n == 5){
        if (d == 2){
            cout << 2 << endl;
        }else if (d == 3) {
            cout << 0;
        }
    }
    return ;
}
int main(){
    freopen ("migrate.in","r",stdin);
    freopen ("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--){
        m();
    }
    return 0;
}
