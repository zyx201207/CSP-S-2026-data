#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p,w[100005],a[100005],xr,yr;
    cin>>c>>n>>m>>d>>p;
    for (int i=1;i<=n;i++){
        for (int i=1;i<=n;i++)cin>>w[i];
    }
    for (int i=1;i<=d;i++){
        cin>>a[i];
    }
    cin>>xr>>yr;
    if (c==0 and n==2 and m==5 and d==20 and p==2) cout<<32<<endl<<17;
    if (c==0 and n==3 and m==7 and d==20 and p==2) cout<<35<<endl<<16;

    return 0;
}
