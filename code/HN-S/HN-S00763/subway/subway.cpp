#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NR = 505;
const int MR = 5e5 + 5;
const int DR = 25;
struct asdf{
    int id,sum;
};
int cid,n,m,d,q;
int a[MR];
vector <asdf> v[MR];
int c[NR][NR];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> cid >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            int x,t;
            cin >> x >> t;
            v[x].push_back({i,t});
        }
    }
    memset(c,0x3f,sizeof(c));
    for(int i = 1;i <= n;i++) c[i][i] = 0;
    for(int i = 1;i <= m;i++){
        for(asdf j : v[i]){
            for(asdf k : v[i]){
                if(j.id == k.id) continue;
                c[j.id][k.id] = c[k.id][j.id] = min(c[j.id][k.id],j.sum + k.sum);
            }
        }
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++) c[i][j] = min(c[i][j],c[i][k] + c[k][j]);
        }
    }
    while(q--){
        int s,t;
        cin >> s >> t;
        int res = 1e18;
        for(asdf i : v[s]){
            for(asdf j : v[t]){
                res = min(res,c[i.id][j.id] + i.sum + j.sum);
            }
        }
        cout << a[s] + a[t] + res << "\n";
    }
    return 0;
}
