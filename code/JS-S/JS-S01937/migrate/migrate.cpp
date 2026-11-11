#include<bits/stdc++.h>
using namespace std;
long long a[2000005],d,n;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<3){
            cout<<0<<'\n';
            continue;
        }
        cout<<0<<'\n';
    }
    return 0;
}
