#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=1010;
int c,n,m,d,q;
int re[MAXN][MAXN];
int w[MAXN];
int tre[MAXN],are[MAXN];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            re[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++)re[i][i]=0;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int tt=1;tt<=n;tt++){
        int tk;
        cin>>tk;
        for(int j=1;j<=tk;j++){
            cin>>are[j]>>tre[j];
        }
        for(int i=1;i<tk;i++){
            for(int j=i+1;j<=tk;j++){
                re[are[i]][are[j]]=min(re[are[i]][are[j]],tre[i]+tre[j]);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                re[i][j]=min(re[i][j],re[i][k]+re[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int tx,ty;
        cin>>tx>>ty;
        cout<<w[tx]+w[ty]+re[tx][ty]<<"\n";
    }
    return 0;
}/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
