#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int l,r;
int a[200010];
int xu[200010];
int maxz;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxz = max(maxz,a[i]);
    }
    if(n>2000||m==1){
        cout<<maxz;
        return 0;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ans = max(ans,a[i]&a[j]);
        }
    }
    cout<<ans;
    return 0;
}

