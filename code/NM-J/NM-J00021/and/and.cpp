#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<=i+m-1;j++){
            ans=max(ans,a[i]&a[j]);
        }
    }
    cout<<ans;
    return 0;
}