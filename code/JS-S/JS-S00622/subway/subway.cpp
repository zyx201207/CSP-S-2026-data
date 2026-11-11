#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[505];
int ans[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++)cin>>a[i];
    for(int i = 1;i <= n;i++){
        int k;
        cin>>k;
        for(int j = 1;j <= k;j++){
            int t,an;
            cin>>an>>t;
            ans[an]+=t;
        }
    }
    int x,y;
    for(int i = 1;i <= q;i++){
        cin>>x>>y;
        cout<<ans[x]+a[y]+a[x]+ans[y]<<endl;
    }
    return 0;
}
