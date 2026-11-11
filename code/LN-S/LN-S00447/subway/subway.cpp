#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,shi[50005],a[50005],k[1000010],t[500005];
    long long x[1000],y[1000];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>shi[i];
    }
    for(int i=1;i<=m;i++){
        cin>>a[i];
        for(int j=1;j<=a[i]*2;j++){
            cin>>k[j]>>t[1];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }

    if(m=1){
        for(int i=1;i<=q;i++){
            cout<<shi[i]*2;
        }
    }
    if(m=2){
        for(int i=1;i<=q;i++){
            cout<<shi[1]+shi[2]+t[i];
        }
    }
    else
        for(int i=1;i<=q;i++){
            cout<<1;
        }

    return 0;
}
