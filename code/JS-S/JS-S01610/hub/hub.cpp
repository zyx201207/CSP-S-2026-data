#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k;
vector<int>tree[20];
int vis[20];


signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> c >> t;


    if(true){
        while(t--){
            cin >> n >> k;
            int u,v;
            for(int i = 1;i < n;i++)
                cin >> u >> v;
            if(k == n)
                cout << 0 << '\n';
            else if(k >= n / 2)
                cout << 1 << '\n';
            else
                cout << 1 + (n / 2 - k + 1) / 2 << '\n';
        }
        return 0;
    }
}