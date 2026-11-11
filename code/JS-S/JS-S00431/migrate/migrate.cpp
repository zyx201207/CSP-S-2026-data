#include<bits/stdc++.h>
using namespace std;
long long tar[2000045];
int ju[2000045];
typedef long long ll;
void solve(){
    int n;ll d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>tar[i];
    }
    if(n<4){
        cout<<0<<endl;
        return;
    }
    int ans=n+1;
    for(int i=1;i<=n;i++){
        if((tar[2]-tar[1])*i>d){
                ans=i;
            break;
        }
    }
    if(2*ans-1 > n){
        cout<<0;
        return;
    }
    if(ans<3){
        cout<<0;
        return;
    }
    cout<<2;
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;cin>>c>>t;
    while(t--){
        solve();
    }
}
