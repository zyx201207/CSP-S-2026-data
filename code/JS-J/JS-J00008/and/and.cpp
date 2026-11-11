#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],x,ans=-9999,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m;i++){
        x=a[i];
        for(int j=i+1;j<=m+i-1;j++){
            x&=a[j];
        }
        ans=max(ans,x);
    }
    cout<<ans;
    return 0;
}
