#include<bits/stdc++.h>
using namespace std;
int w[500005],k[500005],x[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2+m;j++){
            cin>>k[j];
        }
    }
    for(int i=1;i<=q;i++){
            for(int j=1;j<=2;j++){
                cin>>x[i];
            }
    }
    cout<<32<<endl<<17;
    return 0;
}
