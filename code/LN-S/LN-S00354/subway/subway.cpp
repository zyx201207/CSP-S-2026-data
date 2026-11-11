#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sum,dep;
struct banana{
    int x,y;
}r;
int w[20003][21];
int a[500][20000],t[500][20000],k[500000],b[501];
int flood(int x,int y,int deep,int roads){
    if(deep>dep){
        return 0;
    }
    for(int i=1;i<=d;i++){
        if(w[x][i]==1){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==y){
                    if(deep<dep){
                        dep=deep;
                    }
                    return dep;
                }else{
                    flood(a[i][j], y,deep,roads+t[i][x]+t[i][j]);
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i][0];
        for(int j=1;j<=d;j++){
            w[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        b[i]=i;
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][k[i]]>>t[i][k[i]];
            w[a[i][k[i]]][b[i]]=1;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r.x>>r.y;
        dep=999999;
        flood(r.x,r.y,1,w[r.x][0]);
    }
    return 0;
}
