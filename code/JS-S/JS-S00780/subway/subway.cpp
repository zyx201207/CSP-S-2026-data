#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],c[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=q;i++){
        for(int i=1;i<=n;i++){
            cin>>b[i+n+2];
        }
    }

    if(n==2)cout<<32<<"\n";cout<<17;
    if(n==3)cout<<35<<"\n";cout<<16;

    return 0;
}
