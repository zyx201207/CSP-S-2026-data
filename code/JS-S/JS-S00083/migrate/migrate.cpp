#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;
ll n,d,a[2000020];
void s(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x=a[2]-a[1];
    if(2*x>d){
        cout<<0<<endl;
        return ;
    }
    cout<<n-(d/x+1)*2+3<<endl;
}
void solve(){
    ll cnt=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+3;j<=n;j++){
            if(a[j]-a[i]==2*d-1){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            s();
        }
        return 0;
    }
    while(t--){
        solve();
    }
    return 0;
}
