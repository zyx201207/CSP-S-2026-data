#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    if (m == 1){
        cout << n << endl;
        return 0;
    }
    if (m == 2){
        cout << n << n << endl;
        return 0;
    }
}
