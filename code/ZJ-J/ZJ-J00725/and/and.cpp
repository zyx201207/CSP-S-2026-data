#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> r;
    for(int i=1;i<=n;i++) r.push_back(a[i]);
    int ans=0;
    for(int i=30;i>=0;i--){
        vector<int> cur;
        for(int j:r)if(j>>i&1) cur.push_back(j);
        if((int)cur.size()<m) continue;
        swap(r,cur),ans+=(1<<i);
    }
    cout<<ans;
    return 0;
}