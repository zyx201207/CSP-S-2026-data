#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[1005],b[1005];
    cin >> n >> m;
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    for (int i = 0;i < m;i++){
        b[i] = a[i]% pow(10,i + 1) * pow(2,i);
        a[i] /= pow[10,i + 1];
    }
    for (int i = 0;i < n;i++){
        cout << b[i];
    }
    return 0;
}
