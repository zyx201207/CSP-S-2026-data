#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct E{
    ll to, value;
};

bool s(E x, E y){
    return x.value <= y.value;
}

ll c, n, m, d, q, w[500010], ans = 0;
vector<E> edge[510];
vector<pair<ll, ll> > ways[510];
ll ans_[1010];

void dfs(ll x, ll y, ll z, ll thisans){
    ans_[z] = thisans;
    //cout << x << y << z << thisans << endl;
    if(y == z){
        ans = min(ans, thisans);
        return;
    }
    for(ll i = 0;i < edge[z].size();i++){
        if(thisans >= ans_[edge[z][i].to]){
            continue;
        }
        dfs(x, y, edge[z][i].to, thisans + edge[z][i].value);
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(ll i = 1;i <= m;i++){
        cin >> w[i];
    }
    if(c >= 7 && c <= 11){
        for(ll i = 1;i <= n;i++){
            ll k = 0;
            cin >> k;
            if(k == 1){
                cin >> k >> k;
            }
            else{
                ll x = 0, y = 0, x_ = 0, y_ = 0;
                cin >> x >> x_ >> y >> y_;
                edge[x].push_back({ y, x_ + y_ });
                edge[y].push_back({ x, x_ + y_ });
            }
        }
        for(ll i = 1;i <= q;i++){
            ans = LLONG_MAX;
            memset(ans_, 0x3f, sizeof(ans_));
            ll x, y;
            cin >> x >> y;
            dfs(x, y, x, 0);
            cout << w[x] + w[y] + ans << endl;
        }
    }
    else{
        int cnt = m;
        int time = 0;
        for(ll i = 1;i <= n;i++){
            ll k = 0;
            cin >> k;
            cnt++;
            for(int i = 1;i <= k;i++){
                int x = 0;
                cin >> x;
                cin >> time;
                edge[x].push_back({ cnt, time });
                edge[cnt].push_back({ x, time });
            }
        }
        for(ll i = 1;i <= q;i++){
            ans = LLONG_MAX;
            memset(ans_, 0x3f, sizeof(ans_));
            ll x, y;
            cin >> x >> y;
            dfs(x, y, x, 0);
            cout << w[x] + w[y] + ans << endl;
        }
    }
    return 0;
}
