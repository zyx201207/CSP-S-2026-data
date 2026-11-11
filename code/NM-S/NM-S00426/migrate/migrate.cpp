#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,a[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        cout<<ans;
    }
    return 0;
}
