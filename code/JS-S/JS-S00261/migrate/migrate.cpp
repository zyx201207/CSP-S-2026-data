#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int a[2000005];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int tmp=d*2;
        int ans=n-tmp+1;
        cout<<ans<<'\n';
    }
    return 0;
}
