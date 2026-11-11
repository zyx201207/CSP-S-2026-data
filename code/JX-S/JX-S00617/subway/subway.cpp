#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int MAXM=1e5*5+2;
int w[MAXM];
ll mt[MAXM];
vector <int> he[MAXM];
vector <int> ed,ti;
void dfs(int x,int y,ll ans){
    int y0,t0;
    for(int i=0;i<he[x].size();i++){
        y0=ed[i];
        t0=ti[i];
        if(mt[y0]==0){
            mt[y0]=t0+ans;
        }
        else{
            mt[y0]=min(t0+ans,mt[y0]);
        }
        if(y0==y){
        }
        else{
            dfs(y0,y,mt[y0]);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    int k,a0,t0=2e9,x0,y0,t1=2e9,tol=0;
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%d%d",&x0,&y0);
            t0=min(t0,x0);
            t1=min(t1,y0);
        }
    }
    int x,y;
    ull ans;
    for(int i=0;i<q;i++){
        scanf("%d%d",&x,&y);
        ans=w[x]+w[y]+t1+t0;
        printf("%lld\n",ans);
    }
    return 0;
}
