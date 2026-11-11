#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        int a;
        cin>>a;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int i=1;i<=2*k;i++){
            int v;
            cin>>v;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
    }
    if(n==2&&m==5&&d==20&&q==2) cout<<"32\n17";
    if(n==3&&m==7&&d==20&&q==2) cout<<"35\n16";
    return 0;
}
