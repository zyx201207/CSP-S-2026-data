#include<bits/stdc++.h>
using namespace std;
const int Maxx=1e9+7;
int c,n,m,d,q;
int mp[10505][10505];
int ga[500005];
void flo(){
    for(int k=1;k<=m+n;k++){
        for(int i=1;i<=n+m;i++){
            for(int j=1;j<=n+m;j++){
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>ga[i];
    }
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            mp[i][j]=Maxx;
            mp[j][i]=Maxx;
            if(i==j)mp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            mp[i+m][a]=t;
            mp[a][i+m]=t;
        }
    }
    flo();
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<(mp[x][y]+ga[x]+ga[y])<<'\n';
    }
    return 0;
}
