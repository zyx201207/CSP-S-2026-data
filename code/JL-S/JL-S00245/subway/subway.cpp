#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int w,v;
};
int c,n,m,d,q;
int h[500005];
int dis[1505][1505];
int a[1505][1505];
void floyd(){
    for(int k=1;k<=n+m;k++){
        for(int i=1;i<=m+n;i++){
            for(int j=1;j<=m+n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}
signed main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            a[i][j]=100000000;
            if(i==j) a[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int v,w;
            cin>>v>>w;
            a[m+i][v]=w;
            a[v][m+i]=w;
        }
    }


    floyd();


    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<a[x][y]+h[x]+h[y];
    }
    return 0;
}

