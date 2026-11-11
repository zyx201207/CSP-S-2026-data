#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==m){
        int ans=LLONG_MAX;
        for(int a=0;a<n;a++){
            int q;
    cin>>q;
    ans&=q;
        }
        cout<<ans;
        return 0;
    }
    else{
            int ans=0;
        for(int a=0;a<n;a++){
            int q;
    cin>>q;
    ans=max(ans,q);
        }
        cout<<ans;
        return 0;
    }
}
