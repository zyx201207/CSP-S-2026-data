#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[1005];
    cin >> n;
    for (int i = 0;i < n;i ++){
        cin >> a[i];
    }
    if(n == 1){
        cout << 1;
    }
    else if (n == 2){
        cout << a[3];
    }
    else if {
        cout << a[2 * n - 1];
    }
    return 0;
}
