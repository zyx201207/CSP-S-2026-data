#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>=4){
                if(a[i]-a[i-3]>d&&a[i]-a[i-3]<=2*d)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
