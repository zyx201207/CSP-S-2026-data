#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,d;
    cin>>n>>d;
    vector<int> x(n+1);
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    cout<<(n-d-1)<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}
