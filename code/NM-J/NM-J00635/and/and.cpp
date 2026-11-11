#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    int m, n;
    int a[100000001];
    cin >> m >> n;
    for(int i; i <= m; i++){
        cin >> a[i];
    }
    while(true){
        int w = a[i] & a[i+1];
        cout << w;
        break;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
