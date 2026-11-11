#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],u,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(u<=m){
            u+=(a[i+1]-a[i])*i;
            if(u>m) u-=(a[i+1]-a[i])*i;
            else ans++;
        }
        else break;
    }
    cout<<ans;
    return 0;
}
