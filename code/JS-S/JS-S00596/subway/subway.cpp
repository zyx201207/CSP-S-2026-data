#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
struct Subway{
    int sta;
    int time;
}a[507][3];
int c,n,m,d,q;
int station[N];
int way[507];
bool vis[N];
int dfs(int x,int y,int tp,int s){
    //cout<<tp<<endl;
    if(tp==y){
        return s;
    }
    int minn=INT_MAX;
    for(int i=1;i<=n;i++){
        int t;
        bool f=false;
        for(int j=1;j<=way[i];j++)
            if(a[i][j].sta==tp){
                f=true;
                t=a[i][j].time;
            }

        if(f==true){
            for(int j=1;j<=way[i];j++){
                if(a[i][j].sta!=tp&&vis[a[i][j].sta]==0){
                    vis[tp]=1;
                    minn=min(minn,dfs(x,y,a[i][j].sta,s+a[i][j].time+t));
                    vis[tp]=0;
                }
            }
        }
    }
    return minn;

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>station[i];
    }
    for(int i=1;i<=n;i++){
        cin>>way[i];
        for(int j=1;j<=way[i];j++){
            cin>>a[i][j].sta;
            cin>>a[i][j].time;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<dfs(x,y,x,station[x]+station[y])<<endl;
    }
    return 0;
}
/*
0 5 4 999 2
1 1 1 1
2 1 10 3 10
2 1 1 2 1
2 2 1 3 1
2 1 2 4 1
2 4 1 3 1
1 3
1 4
*/
