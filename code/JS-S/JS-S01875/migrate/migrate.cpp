#include <bits/stdc++.h>
using namespace std;
bool vis[5005][5005];
int p[5005];
struct sb{
    int pl;
    int x;
};
bool bfs(int s, int e){
    sb bigsb;
    bigsb.pl = s;
    bigsb.x = 0;
    queue <sb> q;
    q.push(bigsb);
    int ans = 191981024;
    int sbbb = 0;
    bool f = true;
    while(!q.empty()){
        sb now = q.front();
        q.pop();
        if(now.pl==e&&(f||now.x==ans)){
            ans = now.x;
            f = false;
            sbbb++;
        }
        if(sbbb>2){
            return false;
        }
        for(int i=now.pl+1;i<=e;i++){
            if(vis[now.pl][i]&&now.x+1<=ans){
                sb nt;
                nt.pl = i;
                nt.x = now.x + 1;
                q.push(nt);
            }
        }
    }
    if(sbbb==2){
        return true;
    }
    return false;
}
int main(){
    int t,c;
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t!=0){
        int n, d;
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> p[i];
        }
        //cout << "??????????????????????????????????????????????????";
        memset(vis, false, sizeof(vis));
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(p[j]-p[i]<=d){
                    vis[i][j] = true;
                }
            }
        }
        int cnt = 0;
        //cout << "??????????????????????????";
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cnt += int(bfs(i, j));
            }
        }
        cout << cnt << "\n";
        t--;
    }

    return 0;
}
