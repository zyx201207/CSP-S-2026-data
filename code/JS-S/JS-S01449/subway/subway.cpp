#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,subnub[500],sub[500][500][3],w[20010],qi[100010],mo[100010],vis[20010];
int dis(int x,int y){
    vis[x]=1;
    int xi=-1,xj=-1,yi=-1,yj=-1,dmin=INT_MAX;
    for(int i=1;i<=n;i++){
        xi=-1,xj=-1,yi=-1,yj=-1;
        for(int j=1;j<=subnub[i];j++){
            if(sub[i][j][0]==y)yi=i,yj=j;
            if(sub[i][j][0]==x)xi=i,xj=j;
        }if(xi!=-1&&yi!=-1)dmin=min(dmin,sub[xi][xj][1]+sub[yi][yj][1]);
    }
    if(dmin!=INT_MAX) return dmin;
    else{
        for(int i=1;i<=n;i++){
            xi=-1,xj=-1;
            for(int j=1;j<=subnub[i];j++){
                if(sub[i][j][0]==x)xi=i,xj=j;
            }if(xi!=-1){
                for(int j=1;j<=subnub[i];j++){
                    if(j!=xj&&vis[sub[i][j][0]]==0){
                        dmin=min(dmin,(dis(sub[i][j][0],y)+dis(sub[i][j][0],x)));
                        //cout<<dmin<<endl;
                    }
                }
            }
        }
        return dmin;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>subnub[i];
        for(int j=1;j<=subnub[i];j++){
            cin>>sub[i][j][0]>>sub[i][j][1];
        }
    }
    for(int i=1;i<=q;i++){
        for(int i=1;i<=m;i++) vis[i]=0;
        cin>>qi[i]>>mo[i];

        cout<<dis(qi[i],mo[i])+w[qi[i]]+w[mo[i]]<<endl;
    }
    return 0;
}
