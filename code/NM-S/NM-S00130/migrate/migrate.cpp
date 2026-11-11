#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n;
ll d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        vector<ll> pos(n+1);
        for(int i=1;i<=n;i++) cin>>pos[i];
        if(d<=pos[2]-pos[1]) cout<<0<<'\n';
        else{
            int k=(d/(pos[2]-pos[1]));
            cout<<n-k-1<<'\n';
        }
    }
}
