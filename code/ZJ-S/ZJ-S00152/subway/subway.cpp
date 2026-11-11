#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005],k[500005],a[505][5005],t[505][5005];
vector<int> e[500005],mid;
set<int> in[500005];
int dfs(int x,int y,int cost,int last){
    for(auto i:in[x]){
        for(auto p:e[i]){
            if(p == y)
                return cost+t[i][y];
            if(in[p].size()==1||p==x)
                continue;
            else{
                //cout << i << " " << p << "\n";
                for(auto j:in[p]){
                    if(i == j)
                        continue;
                    //cout << j << " " << last << " " << x << " " << "\n";
                    return dfs(p, y, cost + t[last][p] + t[j][p],j);
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i = 1; i <= m;i++){
        cin >> w[i];
    }
    for (int i = 1; i <= n;i++){
        cin >> k[i];
        for (int j = 1; j <= k[i];j++){
            cin >> a[i][j] >> t[i][a[i][j]];
            e[i].push_back(a[i][j]);
            in[a[i][j]].insert(i);
        }
    }
    while(q--){
        int x, y,minn=0x3fffff;
        bool flag = false;
        cin >> x >> y;
        for (auto i:in[x]){
            if (in[y].count(i)){
                cout << w[x] + w[y] + t[i][x] + t[i][y]<<"\n";
                flag = true;
                break;
        }}
        if(flag)
            continue;
        for(auto i:in[x]){
            minn=min(minn,w[x]+w[y]+t[i][x]+dfs(x,y,0,i));
        }
        cout << minn<<"\n";
    }
    return 0;
}