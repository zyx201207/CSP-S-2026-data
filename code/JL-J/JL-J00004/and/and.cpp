#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200010],ans;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ll mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    ll fres=a[1];
    for(int i=2;i<=n;i++){
        fres&=a[i];
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==n){
        cout<<fres;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    ll ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
