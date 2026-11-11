#include<bits/stdc++.h>
using namespace std;
struct zhan{
    int xian[20];
    int t[20];
    int zhizhen=0;
};
vector<int>www;
vector<zhan>zz;
void sc(int m,int n){
    int scb,k;
    www.resize(m+1);
    for(int i=1;i<=m;i++){
        scanf("%d",&scb);
        www[i]=scb;
    }
    int a,t;
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%d %d",&a,&t);
            zz[a].xian[zz[a].zhizhen]=i+1;
            zz[a].t[zz[a].zhizhen]=t;
            zz[a].zhizhen++;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    zz.resize(m+1);
    sc(m,n);
    int ddd[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ddd[i][j]=1000000001;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<zz[i].zhizhen;j++){
            for(int k=j+1;k<zz[i].zhizhen;k++){
                if(ddd[zz[i].xian[j]][zz[i].xian[k]]>zz[i].t[j]+zz[i].t[k]){
                    ddd[zz[i].xian[j]][zz[i].xian[k]]=zz[i].t[j]+zz[i].t[k];
                    ddd[zz[i].xian[k]][zz[i].xian[j]]=zz[i].t[j]+zz[i].t[k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(j!=k&&ddd[j][k]>ddd[j][i]+ddd[i][k]) ddd[j][k]=ddd[j][i]+ddd[i][k];
            }
        }
    }
    for(int i=1;i<=n;i++){
        ddd[i][i]=0;
    }
    int x,y,tot,gd=1000000000;
    bool gong;
    for(int i=0;i<q;i++){
        scanf("%d %d",&x,&y);
        gong=1;
        tot=1000000000;
        for(int j=0;j<zz[x].zhizhen;j++){
            for(int k=0;k<zz[y].zhizhen;k++){
                if(tot>zz[x].t[j]+zz[y].t[k]+www[x]+www[y]+ddd[zz[x].xian[j]][zz[y].xian[k]])tot=zz[x].t[j]+zz[y].t[k]+www[x]+www[y]+ddd[zz[x].xian[j]][zz[y].xian[k]];
            }
        }
        printf("%d\n",tot);
    }
    return 0;
}

