#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t >> t;
    while(t --){
        int n,k;
        cin >> n >> k;
        if(k == n) cout << 0 << endl;
        else cout << n-k << endl;
    }
}
