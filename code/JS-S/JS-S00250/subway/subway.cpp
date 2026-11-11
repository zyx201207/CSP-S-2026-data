#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+10;
ll c,n,m,d,q,w[MAXN],k[510],a[510][25],t[510][25],x,y;
void solve(ll a1,ll b1){
    
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<abs(x-y)*t[1][1];
    }
    return 0;
}