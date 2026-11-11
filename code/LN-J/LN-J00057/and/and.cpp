#include<bits/stdc++.h>
using namespace std;
long long a[200005],b,n,m,ans=0,ma1=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ma1=a[1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma1=max(ma1,a[i]);
    }if(m==1){cout<<ma1;return 0;}
    sort(a+1,a+1+n);
    ans=a[n];
    for(int i=1;i<=m;i++){
        ans&=a[n-i+1];
    }
    cout<<ans;
    return 0;
}
