#include <bits/stdc++.h>
using namespace std;
int f[10000];
int e[10000];
int s[10000];
int st[10000];
int en[10000];
int yy[10000];
int c,n,m,d,q;
int w;
int cnt;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>f[i];
    }
    for(int i=1;i<=n;i++){
        cin>>w;
        yy[i]=w;
        for(int j=1;j<=w;j++){
            cin>>e[j]>>s[j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>st[i]>>en[i];
    }

    return 0;
}
