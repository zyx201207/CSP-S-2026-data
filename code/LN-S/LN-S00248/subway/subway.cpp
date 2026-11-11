#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Q=100005;
LL c,n,m,d,q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    LL w[Q],a[Q],t[Q],k[Q],x[Q],y[Q],r;
    int sat=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i]>>a[i]>>t[i];
    }
    for(int i=1;i<=r;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*k[i];i++){
            for(int v=1;v<=2*k[i];i++){
                if(a[j]==x[i]&&a[v]==y[i]){
                    sat=w[x[i]]+t[x[i]]+w[y[i]]+t[y[i]];
                }
                else if(a[j]==x[i]||a[v]==y[i]){
                    sat=w[x[i]]+t[x[i]]+w[y[i]]+t[y[i]];
                }
            }
        }
    }
    cout<<sat;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
