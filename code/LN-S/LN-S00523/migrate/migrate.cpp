#include <iostream>
using namespace std;
int c,t;
int ar[100000];
int fa[100000];
int vis[100000];
int n,d;
/*
void init(){
    scanf("%d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%d",&ar[i]);
    }
    for(int i=1;i<=n;i++){
        fa[i]=i,vis[i]=1;
    }
}
int found(int x){
    if(fa[x]==x)
        return x;
    return fa[x]=found(fa[x]);
}
void bing(int x,int y){
    x=found(x);
    y=found(y);
    if(x!=y)
        fa[x]=y;
    vis[x]+=vis[y];
    return ;
}
void f(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(abs(ar[i]-ar[j])<=d){
                bing(i,j);
            }
        }
    }
}
void solve(){
    f();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(found(i)==found(j))
                printf("%d,%d = %d\n",i,j,vis[i]+vis[j]);
        }
    }
}
*/
struct edge{
    int l,r;
};
edge a[1000000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&ar[i]);
        }
        for(int j=1;j<=n;j++){
            a[j].r=lower_bound(ar+1,ar+1+n,ar[j]+d)-ar;
            a[j].l=lower_bound(ar+1,ar+1+n,ar[j]-d)-ar;
            if(a[j].r>n)
                a[j].r=n;
            if(a[j].l<=1)
                a[j].l=1;
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                int a,b;
                a=abs(ar[j].r-ar[k].l)+1;
                dp[j][k]=a;
                b=abs(ar[j].l-ar[k].r)+1;
                dp[k][j]=b;
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dp[j][k]==2)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
