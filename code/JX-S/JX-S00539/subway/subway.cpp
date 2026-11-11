#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500050
#define M 2000000
int c,n,m,d,q;
int a[N],x[N],t[N],head[M],nxt[M],ver[M],edge[M],tot;
void add(int a,int b,int c){
    nxt[++tot]=head[a];
    head[a]=tot;
    ver[tot]=b;
    edge[tot]=c;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d%d",&x[j],&t[j]);
        }
        for(int j=1;j<=k;j++)
        for(int l=j+1;l<=k;l++){
            add(i,l,t[j]+t[l]);
            add(l,i,t[l]+t[j]);
        }
    }
    return 0;
}
