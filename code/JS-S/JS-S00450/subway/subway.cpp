#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
const int maxm=5e5+5;
const int maxq=1e5+5;
const int maxd=20;
int c,n,m,d,q;
int w[maxm];
int k[maxn];
int a[maxn][maxm],t[maxn][maxm];
int r[maxq];
int dis[maxn][maxn];
struct station{
    int in;
    vector<int> ofline;
    vector<int> t;
}s[maxm];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
        s[i].in=w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][a[i][j]];
            s[a[i][j]].ofline.push_back(i);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        for(int a:s[i].ofline){
            for(int p:s[i].ofline){
                if(a==p){
                    continue;
                }
                dis[a][p]=min(dis[a][p],t[a][i]+t[p][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dis[i][j]=0;
            }
            if(j<i){
                dis[i][j]=dis[j][i];
            }
            for(int k=0;k<=n;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int st,en;
        cin >> st >> en;
        int ans=0x3f3f3f3f;
        for(auto a:s[st].ofline){
            for(auto p:s[en].ofline){
                ans=min(ans,w[st]+w[en]+t[a][st]+t[p][en]+dis[a][p]);
            }
        }
        cout << ans << endl;
    }
}

