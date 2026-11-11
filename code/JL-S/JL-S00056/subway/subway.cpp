#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],t[10005],b[10005][10005],c[10005][10005];
bool f[10005][10005];
int dfs(int x,int xx,int y,int ans){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]!=0){
                if(j==y) return ans;
                else if(c[i][j]!=c[x][xx]&&f[i][j]){
                    dfs(i,j,y,ans+t[xx]);
                    f[i][j]=false;
                }
                cout<<i<<" "<<j<<'\n';
            }
        }
    }
}
int ne(int x,int y){
    for(int i=y+1;;i++){
        if(c[x][i]!=0) return i;
    }
}
int main(){
    freopen("subway.in", "r",stdin);
    freopen("subway.out","w",stdout);
    int gm,d,q;
    cin>>gm>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int xx,tt;
            cin>>xx>>tt;
            b[i][xx]=tt;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            t[j]+=b[i][j];
            if(b[i][j]!=0){
                c[j][ne(i,j)]=i;
                c[ne(i,j)][j]=i;
                cout<<j<<" "<<ne(i,j)<<" ";
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<'\n';
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int minn=INT_MAX;
        for(int j=1;j<=m;j++){
            if(c[x][j]!=0){
                minn=min(minn,dfs(x,y,a[x]+a[y],c[x][j]));
            }
        }
        cout<<minn<<'\n';
    }
    return 0;
}
//Segmentation fault (core dumped)?
