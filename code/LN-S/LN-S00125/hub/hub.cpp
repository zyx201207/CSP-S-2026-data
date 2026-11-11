#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
long long an=1e18;
struct eg{
    int t,n;
}a[2000010];
int r[1000010],p;
bool b[1000010];
int ds[4005][4005];
void ad(int x,int y){
    a[++p]={y,r[x]};
    r[x]=p;
}
void dfs(int ro,int x,int fa){
    ds[ro][x]=ds[ro][fa]+1;
    for(int i=r[x];i;i=a[i].n){
        int t=a[i].t;
        if(t!=fa) dfs(ro,t,x);
    }
}
void so(){
    long long ma=0;
    for(int i=1;i<=n;i++){
        if(b[i]) continue;
        long long mi=1e18;
        for(int j=1;j<=n;j++){
            if(b[j]){
                mi=min(mi,1ll*ds[i][j]);
            }
        }
        ma=max(ma,mi);
    }
    an=min(an,ma);
}
void sp(int x,int ct){
    b[x]=1;
    if(ct==k){
        so();
        b[x]=0;
        return;
    }
    for(int i=x+1;i<=n-k+ct+1;i++) sp(i,ct+1);
    b[x]=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        an=1e18;
        memset(a,0,sizeof(a));
        p=0;
        memset(r,0,sizeof(r));
        memset(ds,0,sizeof(ds));
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            ad(x,y);
            ad(y,x);
        }
        for(int i=1;i<=n;i++){
            ds[i][0]--;
            dfs(i,i,0);
            ds[i][0]++;
        }
        sp(0,0);
        printf("%lld\n",an);
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<ds[i][j]<<' ';
            }
            cout<<"\n";
        }*/
    }

    return 0;
}
