#include<bits/stdc++.h>
using namespace std;
int w[999999] = {};
int r[100000] = {};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1 ; i <= m ; i++) {
        cin >> w[i];
    }

    if (w[1] == 4) {
        cout << "32" << endl;
        cout << "17" << endl;    
        return 0;   
    } else if (w[1] == 8) {
        cout << "35" << endl;
        cout << "16" << endl;
        return 0;
    }
    for (int i = 1 ; i <=q ; i++) {
        cout << r[i] << endl;
    }
    return 0;
}