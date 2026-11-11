#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans;
bool f[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=30;i>=0;i--){
        int h=0;
        for(int j=1;j<=n;j++)
            if((a[j]&(1<<i))&&!f[j]) h++;
        if(h>=m){
            ans+=(1<<i);
            for(int j=1;j<=n;j++)
                if(!(a[j]&(1<<i))) f[j]=1;
        }
    }
    cout<<ans;
    return 0;
}
