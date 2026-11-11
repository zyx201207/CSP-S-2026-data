#include<bits/stdc++.h>
using namespace std;
int w[5000005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q,ans=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    cout<<ans;
    return 0;
}

