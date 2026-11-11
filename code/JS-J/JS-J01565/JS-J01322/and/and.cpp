#include <bits/stdc++.h>
using namespace std;
int n,m,f=INT_MAX;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f&=a[i];
    }
    if(m==1){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(a[i],ans);
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        cout<<f;
        return 0;
    }
    return 0;
}
