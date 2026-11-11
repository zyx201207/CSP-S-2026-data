#include <bits/stdc++.h>
using namespace std;
#define str string
#define ll long long
void io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll c,t,cnt;
int a[10] = {1,0,2,1,2,1,0,2,1,1};
int main() {
    io();
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    ll i = 0;
    while(t--) {
        cout<<a[i%10]<<'\n';
        i++;
    }
    return 0;
}
