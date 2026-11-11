#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+10;
int a[N];


signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1ll){
        int ans =-1ll;
        for(int i=1ll;i<=n;i++){
            int t;
            cin>>t;
            ans=max(ans,t);
        }
        cout<<ans;
    }
    else if(m==2ll){
        int ans=-1ll;
        for(int i=1ll;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1ll;i<=n-1ll;i++){
            for(int j=i+1ll;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(m==n){
        int ans=a[1ll];
        for(int i=2ll;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    return 0;
}
