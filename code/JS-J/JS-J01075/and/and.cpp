#include <bits/stdc++.h>
using namespace std;
int o;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b; cin >> a >> b;
    vector <int> vt;
    for (int i = 0;i < a;i++){
        int x; cin >> x;
        vt.push_back(x);
    }
    sort(vt.begin(),vt.end());
    reverse(vt.begin(),vt.end());
    o = vt[0];
    for (int i = 1;i < b;i++){
        o = o & vt[i];
    }
    cout << o;
    return 0;
}
