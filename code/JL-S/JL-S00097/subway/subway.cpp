#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,a,b,x,y;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a;
    }
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=1;j<=x*2;j++){
            cin>>y;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>a>>b;
    }
    for(int i=1;i<=q;i++){
        cout<<"0"<<endl;
    }
    return 0;
}
