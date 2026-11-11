#include<iostream>
#include<cmath>
using namespace std;
struct edge{
    int u,v,w;
};
int c,n,m,d,q;
int w[1010],s[1010][1010];
bool vis[1010][1010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i==j){
                s[i][j]=-1;
            }else{
                s[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        int a[1010],t[1010];
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                if(s[a[j]][a[l]]==0){
                    s[a[j]][a[l]]=t[j]+t[l];
                }else{
                    s[a[j]][a[l]]=min(t[j]+t[l],s[a[j]][a[l]]);
                }
            }
        }
    }

    for(int aaa=1;aaa<=m*m/2;aaa++){

    int mn=100000000,mn_x,mn_y;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]!=0&&s[i][j]!=-1){
                if(vis[i][j]==0&&mn>s[i][j]){
                    mn=s[i][j];
                    mn_x=i;
                    mn_y=j;
                }
            }
        }
    }
    vis[mn_x][mn_y]=1;
    for(int i=1;i<=m;i++){
        if(s[i][mn_x]!=0&&s[i][mn_x]!=-1){
            if(s[i][mn_y]==0){
                s[i][mn_y]=s[i][mn_x]+s[mn_x][mn_y];
                s[mn_y][i]=s[i][mn_x]+s[mn_x][mn_y];
            }else{
                s[i][mn_y]=min(s[i][mn_x]+s[mn_x][mn_y],s[i][mn_y]);
                s[mn_y][i]=min(s[i][mn_x]+s[mn_x][mn_y],s[i][mn_y]);
            }

        }
    }
    for(int i=1;i<=m;i++){
        if(s[i][mn_y]!=0&&s[i][mn_y]!=-1){
            if(s[i][mn_x]==0){
                s[i][mn_x]=s[i][mn_y]+s[mn_y][mn_x];
                s[mn_x][i]=s[i][mn_y]+s[mn_y][mn_x];
            }else{
                s[i][mn_x]=min(s[i][mn_y]+s[mn_y][mn_x],s[i][mn_x]);
                s[mn_x][i]=min(s[i][mn_y]+s[mn_y][mn_x],s[i][mn_x]);
            }
        }
    }
    /*
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */
    }


    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<(w[x]+w[y]+s[x][y])<<endl;
    }
    return 0;
}
