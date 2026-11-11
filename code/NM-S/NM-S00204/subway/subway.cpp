#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long c,n,m,d,q,k,x,y,sum,s;
long long a[N],b[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>sum;
            b[x]+=sum;
        }
    }
    for(int i=1;i<=q;i++){
        s=0;
        cin>>x>>y;
        for(int j=x;j<=y;j++){
            s+=b[j];
        }
        s+=a[x]+a[y];
    cout<<s<<endl;
    }
    return 0;
}
