#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;++i)cin>>w[i];
    for(int i=0;i<n;++i){
        long long tp,pt;
        cin>>tp;
        for(int j=0;j<2*tp;++j){
            cin>>pt;
        }
    }
    while(q--){
        long long l,r;
        cin>>l>>r;
        cout<<w[l]+w[r]<<"\n";
    }
    return 0;
}
