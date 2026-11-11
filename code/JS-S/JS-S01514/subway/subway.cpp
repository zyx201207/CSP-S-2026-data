#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
struct Ren{
    int k;
    int a[500005];
    int b[500005];
}ren[505];
struct R{
    int be;
    int en;
}r[500005];
int vis[500005][25];
short e[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>ren[i].k;
        for(int j=1;j<=ren[i].k;j++){
            cin>>ren[i].a[j]>>ren[i].b[j];
            vis[ren[i].a[j]][++e[ren[i].a[j]]]=j;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r[i].be>>r[i].en;
    }
    for(int i=1;i<=q;i++){
    }
    return 0;
}
