#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q, ans, minn;

void dfs(vector<vector<int> >& sz, int s, int e, int t){

    if(s == e){
        if(minn == 0) minn = t;
        minn = min(t, minn);
        //printf("结束\n");
        return;
    }
    if(sz[s][e] == -1) return;

    for(int i = 0; i < m; i++){
        if(sz[s][i] != -1){
            //printf("S:%d E:%d T:%d\n", s+1, e+1, t);
            int a = sz[s][i];
            sz[s][i] = -1;
            dfs(sz, i, e, t+a);
            sz[s][i] = a;
        }
    }

}


int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    vector<int> dtz(m);//存地铁站的进出站时间

    for(int i = 0; i < m; i++) cin >> dtz[i];


    vector<vector<int> > lujin(m, vector<int>(m, -1));

    for(int i = 0; i < n; i++){
        int k, js = 0;
        cin >> k;
        vector<pair<int, int> > xl(k*2);
        for(int j = 0; j < k; j++){
            cin >> xl[j].first >> xl[j].second;
            //js +=2;
        }
        //cout << lujin[1][2] << "\n";
        for(int x = 0; x < k; x++){
            for(int y = 0; y < k; y++){
                int a1 = xl[x].first-1, a2 = xl[y].first-1;

                //printf("%d %d   %d+%d=%d\n", a1+1, a2+1, xl[x].second, xl[y].second,xl[x].second + xl[y].second);

                if(lujin[a1][a2] > 0)lujin[a1][a2] = min(lujin[a1][a2],(xl[x].second + xl[y].second));
                lujin[a1][a2] = xl[x].second + xl[y].second;
                //cout << lujin[a1][a2] << "\n";

            }
        }
        //cout << "\n";
    }

    //cout << lujin[0][1] << "\n";

    for(int f = 0; f < q; f++){
        int x, y;
        ans = 0;
        cin >> x >> y;
        x--; y--;
        ans += dtz[x] + dtz[y];//+进站出站时间

        dfs(lujin, x, y, 0);

        ans += minn;

        cout << ans << "\n";
    }
    return 0;
}
