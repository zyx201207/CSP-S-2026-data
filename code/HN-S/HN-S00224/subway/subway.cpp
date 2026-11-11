#include <bits/stdc++.h>
using namespace std;

const int mx=5*1e5+5;
int mrr[mx];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w=0;
    for(int i=1;i<=m;i++)cin>>mrr[i];
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        for(int j=1;j<=x;j++){
            int a,b;cin>>a>>b;w=b;
        }
    }
    for(int i=1;i<=q;i++){
        int r,l;
        cin>>l>>r;
        long long ans=mrr[l]+mrr[r]+1LL*w*(r-l+1);
        cout<<ans<<'\n';
    }


    return 0;
}
