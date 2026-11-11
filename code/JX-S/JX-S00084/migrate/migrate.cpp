#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t,n,d;
const int N = 2e6+5;
int pi[N];
bool vis[N];
void solve(){
    int ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>pi[i];
        vis[pi[i]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(pi[j]-pi[i]==2*d-1&&vis[i+d-1]&&vis[i+d]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
