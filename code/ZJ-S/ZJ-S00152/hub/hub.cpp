#include <bits/stdc++.h>
using namespace std;
int c, t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cout << rand() % 2 + 1<<"\n";
    }
    return 0;
}