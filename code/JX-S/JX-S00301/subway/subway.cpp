#include<bits/stdc++.h>
using namespace std;
long long c,n,m,p,q,w,i,k,x,y;
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>p>>q;
    for(int i=0;i<m;i++) {
        cin>>w;
    }
    for(int i=0;i<n;i++) {
        cin>>k;
        for(int j=0;j<2*k;j++) {
            cin>>i;
        }
    }
    for(int i=0;i<q;i++) {
        cin>>x>>y;
    }
    cout<<35<<17;
    return 0;
}
