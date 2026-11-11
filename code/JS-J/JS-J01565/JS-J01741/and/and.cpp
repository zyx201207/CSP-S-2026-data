#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,k = 0,a[200001],s,x,y = 0;
    cin >> n >> m;
    cin >> a[0];
    s = a[0];
    for (int i = 1;i < m;i++){
        cin >> a[i];
        if (a[i] > k){
            k = a[i];
        }
        x = a[i] & a[i-1];
        s = s & a[i];
        if (x > y){
            y = x;
        }
    }
    if (m == 1){
        cout << k;
    }
    if (m == n){
        cout << s;
    }
    if (m == 2){
        cout << y;
    }
    fclose(stdin);
    fclose(stdout);
}
