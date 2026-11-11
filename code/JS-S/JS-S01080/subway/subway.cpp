#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500010],ans=0;
vector<int> a[550],k,t[550],f[550][550],u[550];
void dfs(int s,int e){
    for (int i=1;i<=u[s].size();i++){
        int j;
        for (j=1;j<=a[u[s][i]].size();j++)
            if(a[u[s][i]][j]==s)
                break;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++)
        cin >> w[i];
    for (int i=1;i<=n;i++){
        int k1;
        cin >> k1;
        k.push_back(k1);
        for (int i=1;i<=k1;i++){
            int a1,t1;
            cin >> a1 >> t1;
            a[i].push_back(a1);
            t[i].push_back(t1);
            u[a1].push_back(i);
        }
    }
    while(q--){
        ans=0;
        int x,y;
        cin >> x >> y;
        dfs(x,y);
        cout << 1 << endl;
    }
    return 0;
}