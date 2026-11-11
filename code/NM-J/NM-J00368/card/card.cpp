#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    string a[100000sss];
    for(int i=1; i<=n; i++){
       cin >> a[i];
       if(a[i]==a[i-1]||a[i]==a[i-2]){
        a[i+1]=a[i];
       }
    }
    cout << a;

return 0;
}
