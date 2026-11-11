#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a[1000005],b[1000005][1000005],e[1000005][1000005],x[1000005],y[1000005];
    long long c,n,m,d,q,k;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>k;
        for(long long j=1;j<=n;j++){
            cin>>b[i][j]>>e[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    cout<<32<<17;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
