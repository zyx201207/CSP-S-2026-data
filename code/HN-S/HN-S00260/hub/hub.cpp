#include<bits/stdc++.h>
#define int long long
#define f(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
int n,k;
void solve(){
    cin>>n>>k;
    f(i,1,n-1){
        int x,y;
        cin>>x>>y;
    }
    cout<<((n+1)/2-k)/4+1<<endl;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t>>t;
    while(t--)solve();
    return 0;
}
