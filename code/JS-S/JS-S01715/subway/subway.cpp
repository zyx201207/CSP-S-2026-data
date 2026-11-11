#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
const int maxm = 2*1e4+2;
int w[maxm];
int t[505][maxm],a[505][maxm];
bool s[505][maxm];
int find(int x,int y){
    bool flag[maxm] = {0};
    int res = 1e6,now = 1e6;
    flag[y] = 1;
    for(int i = 1;i<=n;i++){
        if(s[i][y]&&s[i][x])now = t[i][y]+t[i][x];
        else if(s[i][x]){
            for(int j = 1;j<=n;j++){
                if(s[i][j]&&flag[j]==0){
                    now = t[i][x]+t[i][j]+find(j,y);
                }
                if(now<=res)res = now;
            }
        }
        if(now<=res)res = now;
    }
    return res;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++)scanf("%d",&w[i]);
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        for(int j = 1;j<=k;j++){
            scanf("%d%d",&a[i][j],&t[i][j]);
            s[i][a[i][j]] = 1;
        }
    }
    for(int i = 1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<find(x,y)+w[x]+w[y];
    }
    return 0;
}
