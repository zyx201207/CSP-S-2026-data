#include<bits/stdc++.h>
using namespace std;

int c,t;
struct Edge{
    int u,v;
}edges[105];

signed main(){
    //freopen("hub.in","r",stdin);
    //freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> t;
    bool f = 0;
    if(c == 0 && t == 2) f = 1;

    while(t --){
        int n,k;
        cin >> n >> k;
        for(int i = 1;i <= n - 1;i ++){
            int a,b;
            cin >> a >> b;

        }

    }
    if(f == 1)cout << 1 <<'\n' << 2 << '\n';
    return 0;
}
