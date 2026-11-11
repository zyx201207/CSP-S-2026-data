#include <bits/stdc++.h>
int c,n,m,d,q;
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    vector <int> a[n];
    int k[n+1];
    int maps[n+1][m+1],cnt[m+1][m+1];
    memset(a,0,sizeof(a));
    memset(maps,0,sizeof(maps));
    int w[m+1]={0};
    for (int i=1;i<=m;i++) cin >> w[i];
    for (int i=1;i<=n;i++){
        cin >> k[i];
        for (int j=0;j<k[i];j++){
            int t,b;
            cin >> b >> t;
            maps[i][b]=t+w[i];
            a[i].push_back(b);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<a[i].size();j++){
            for (int p=0;p<a[i].size();p++){
                if (j==p) cnt[a[i][j]][a[i][j]]=0;
                else cnt[a[i][j]][a[i][p]]=maps[i][j];
            }
        }
    }
    for (int i=0;i<q;i++){
        int x,y;
        cin >> x >> y;
        cout << cnt[x][y] << endl;

    }
    return 0;
}
