#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int c, n, m, d, q;
int w[500005],k[505];
bool vis_s[500005],vis_l[505];
vector<int> a[505];
vector<int> b[505];
struct l_o{
    int l;
    int o;
};
vector<l_o> has_line[500005];
int dfs(int s,int goal){
    int ans = 1e8;
    if (s == goal){
        return w[goal];
    }
    for(int i = 0;i < has_line[s].size();i++){
        int line = has_line[s][i].l;
        if (vis_l[line] == 1)continue;
        vis_l[line] = 1;
        for(int j = 0;j < a[line].size();j++){
            if (vis_s[a[line][j]] == 1)continue;
            vis_s[a[line][j]] = 1;
            ans = min(ans,dfs(a[line][j],goal)+b[line][a[line][j] - 1]+b[line][has_line[s][i].o-1]);
            vis_s[a[line][j]] = 0;
        }
        vis_l[line] = 0;

    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    //cout << " wi ";
    for(int i = 1;i <=m;i++){
        cin >> w[i];
        //cout << w[i] << ' ';
    }
    for(int i = 1;i <=n;i++){
        cin >> k[i];
        //cout <<" ki " <<k[i] << ' ';
        for(int j = 1;j<=k[i];j++){
            int x1,x2;
            cin >> x1 >> x2;
            //cout << x1 << ' ' << x2 << ' ';
            a[i].push_back(x1);
            b[i].push_back(x2);
            l_o l;
            l.l = i;
            l.o = j;
            has_line[x1].push_back(l);
        }
    }
    //cout << q << 'q';
    for(int i = 1;i <=q;i++){
        int xr,yr;
        cin >> xr >> yr;
        //cout << xr << yr;
        vis_s[xr] = 1;
        cout << dfs(xr,yr) + w[xr] << endl;
        vis_s[xr] = 0;
    }
    return 0;
}
