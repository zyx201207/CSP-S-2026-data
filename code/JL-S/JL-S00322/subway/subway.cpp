#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500000+10],k;
struct subway{
    ll a;
    ll t;
};
subway a[500000+10];
int main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j].a>>a[j].t;
        }
    }
    return 0;
}
