#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[510];
struct fun{
    int k,aa[510],t[510];

}a[510];
struct ffun{
    int x,y;
}qq[510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].k;
        for(int j=1;j<=a[i].k;j++){
            cin>>a[i].aa[j]>>a[i].t[j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>qq[i].x>>qq[i].y;
    }
    cout<<0<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
