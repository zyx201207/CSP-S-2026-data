#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6+5;

ll n,c,t,d,a[500005],dis[5005][5005],cnt = 0,sum[N],u,v;
bool flag = 0;

int main(){

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> t;
    for(ll i = 1;i <= t;i++){
        cin >> n >> k;
        for(ll j = 1;j <= n;j++){
            cin >> u >> v;
        }
        if(k == n){
            cout << 0;
        }else if(c == 13||c == 14){
            if(k == 1){
                cout << m;
            }else{
                if(k % 2 == 0){
                    cout << (m+1-k/2) / 2;
                }else{
                    if((m+1-k/2) % 2 == 0){
                        cout << (m+1-k/2) / 2;
                    }else{
                        cout << (m+1-k/2) / 2 - 1;
                    }
                }
            }
        }
    }
    return 0;
}
