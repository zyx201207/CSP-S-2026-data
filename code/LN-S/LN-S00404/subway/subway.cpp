#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[500005],t[500005];
int e[5005][5005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(e,0x3f,sizeof(e));
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int ii=1;ii<=k;ii++){
            for(int jj=1;jj<=k;jj++){
                e[a[ii]][a[jj]]=min(e[a[ii]][a[jj]],t[ii]+t[jj]);
                e[a[jj]][a[ii]]=min(e[a[jj]][a[ii]],t[ii]+t[jj]);
            }
        }
    }
    for(int i=1;i<=m;i++) e[i][i]=0;
    for(int mid=1;mid<=m;mid++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(e[i][j]>e[i][mid]+e[j][mid]){
                    e[i][j]=e[i][mid]+e[j][mid];
                }
            }
        }
    }
    for(int r=1;r<=q;r++){
        int x,y;
        cin>>x>>y;
        cout<<e[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}

