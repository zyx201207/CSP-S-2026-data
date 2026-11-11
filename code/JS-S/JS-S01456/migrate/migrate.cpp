#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;
int c,t;
int n,d;
int x[N+5];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>x[i];
        if((x[2]-x[1])*3<=d) cout<<0<<'\n';
        else if((x[2]-x[1])*2>d) cout<<0<<'\n';
        else{
            if(n%2==0) cout<<n*n/4<<'\n';
            else cout<<(n*n-1)/4<<'\n';
        }
    }
    return 0;
}