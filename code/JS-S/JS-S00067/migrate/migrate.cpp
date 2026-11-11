#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010;
ll n,q,a[N],dp[N][N][2];
void solve(){
    ll ch=a[2]-a[1];
    if(ch>q){
        cout<<0<<endl;
        return;
    }
    int temp=q/ch;
    cout<<n-temp<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int task_point,T;
    cin>>task_point>>T;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        solve();
    }

    return 0;
}
