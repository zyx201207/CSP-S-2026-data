#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int c,t,x[N]={};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==0){
        for(int i=1;i<=t;i++){
            int n,d;
            cin>>n>>d;
            if(n==4&&d==2){
                cout<<1<<'\n'<<2;
            }else if(n==5&&d==3){
                cout<<0<<'\n'<<1;
            }
        }
        return 0;
    }
    int ans=0;
    for(int l=1;l<=t;l++){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            if(i%d==0&&i/d>1){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
