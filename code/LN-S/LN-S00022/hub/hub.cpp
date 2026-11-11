#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
constexpr int N = 1e6+10,M = 510;
int testid;
int n,k;
int x,y;
void solve(){
    cin >> n >> k;
    if(k == n) cout << "0\n";
    else if(k >= n / 2){
        cout << "1\n";
    }else{
        int t = (n + 1) / 2;
        cout << (t - k + 3) / 4 + 1;
    }
    for(int i = 1;i < n;i++){
        cin >> x >> y;
    }

}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    //*
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    //*/
    int _ = 1;
    cin >> testid >>  _;
    while(_--) solve();
    return 0;
}
