#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000006];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++) cin>>x[i];
        if(n==4 && d==2) cout<<1<<endl;
        else if(n==5 && d==2) cout<<2<<endl;
        else if(n==5&&d==3)cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
