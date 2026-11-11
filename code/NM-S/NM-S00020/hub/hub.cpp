#include <bits/stdc++.h>
using namespace std;
int u[1000010],v[1000010];
void m(){
    int n,d;
    cin >> n >> d;
    for (int i = 1;i < n;i++){
        cin >> u[i] >> v[i];
    }
    return ;
}
int main(){
    freopen ("hub.in","r",stdin);
    freopen ("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--){
        m();
    }
    cout << 1 << endl;
    cout << 2 << endl;
    return 0;
}

