#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
int a[200005],b[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,a[i]&a[j]);
        }
    }
    cout<<ans;
    return 0;
}
