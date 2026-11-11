#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MM=5e5+100, NN=520, INF=1e18+77;
ll c, n, m, d, q;
ll k[NN], s[NN][NN], w[MM], ln[MM], trans[MM][30][2];
// trans[station][idx]->{line_id, time}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        cin>>k[i];
        for (int j=0;j<k[i];j++){
            ll ta, tt;
            cin>>ta>>tt;
            ln[ta]++;
            trans[ta][ln[ta]][0]=i;
            trans[ta][ln[ta]][1]=tt;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            s[i][j]=INF;
            if (i==j) s[i][j]=0;
        }
    }
    for (int i=1;i<=m;i++){
        for (int ui=1;ui<=ln[i];ui++){
            for (int vi=1;vi<ui;vi++){
                int u, v;
                u=trans[i][ui][0]; v=trans[i][vi][0];
                ll dis; dis=trans[i][ui][1]+trans[i][vi][1];
                if (s[u][v]>dis){
                    s[u][v]=s[v][u]=dis;
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<i;j++){
            for (int k=1;k<=n;k++){
                if (k!=i && k!=j){
                    s[j][i]=s[i][j]=min(s[i][j], s[i][k]+s[k][j]);
                }
            }
        }
    }
    /*for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            printf("s[%d][%d]=%lld\n", i, j, s[i][j]);
        }}*/
    while (q--){
        int u, v;
        cin>>u>>v;
        ll trt=INF;
        for (int i=1;i<=ln[u];i++){
            for (int j=1;j<=ln[v];j++){
                ll nd; nd=s[trans[u][i][0]][trans[v][j][0]]+trans[u][i][1]+trans[v][j][1];
                if (trt>nd){
                    trt=nd;
                    /*printf("%lld=%lld+%lld+%lld [%d][%d]\n", trt,
                           s[trans[u][i][0]][trans[v][j][0]],trans[u][i][1],trans[v][j][1],
                           trans[u][i][0], trans[v][j][0]);*/
                }
            }
        }
        cout<<trt+w[u]+w[v]<<endl;
    }
    return 0;
}
