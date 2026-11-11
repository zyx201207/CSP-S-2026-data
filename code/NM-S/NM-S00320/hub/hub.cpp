#include <bits/stdc++.h>
using namespace std;
#define str string
#define ll long long
void io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int a[10] = {1,1,2,1,0,2,0,1,2,0};
int main() {
    io();
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int i = 0;
    while(t--) {
        cout<<a[i % 10]<<'\n';
        i++;
    }
    return 0;
}
