#include<iostream>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],l[M],s[N],ans[M];
struct range{
    int l,r;
}g[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    int cnt=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if (!l[a[i]]) g[++cnt]={l[a[i]],a[i]};//[pre[a[i]],a[i])
        l[a[i]]=i;
    }
    for (int i=1;i<=cnt;i++){
        if (g[i-1].r<=g[i].l){
            s[g[i].l]-=g[i].l;
            s[g[i].r]+=g[i].l;
        }
        else{
            if (g[i-1].l<g[i].l){
                s[g[i].l]-=g[i].l-g[i-1].l;
                s[g[i].r]+=g[i].l-g[i-1].l;
            }
            else{
                s[g[i].l]-=g[i].l-g[i-1].l;
                s[g[i].r]+=g[i].l-g[i-1].l;
                s[g[i-1].l]-=g[i-1].l;
                s[g[i-1].r]+=g[i-1].l;
            }
        }
    }
    for (int i=1;i<=n;i++){
        s[i]+=s[i-1]+1;
        ans[a[i]]+=s[i];
    }
    for (int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}
