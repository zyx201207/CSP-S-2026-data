#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N];
vector<vector<int>>V;

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    srand(time(0));
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        int mx=0;
        for(int i=1;i<=n;i++) mx=max(a[i],mx);
        cout<<mx;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=1;i<=n;i++) ans&=a[i];
        cout<<ans;
        return 0;
    }
    return 0;
}
