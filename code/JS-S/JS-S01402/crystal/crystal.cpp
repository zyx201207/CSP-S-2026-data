
#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
long long n,m,ans=1;
bool solve(int x){
    long long s=0;
    for (long long i=x;i>=1;i--){
        s=s+a[x]-a[i];
        if (s>m) {
            ans=max(ans,x-i);
            return 0;
        }
    }
    ans=x;
    return 1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=n;i>=1;i--) {
        bool f=solve(i);
        if (f==1) break ;
    }
    cout<<ans;
    return 0;
}
//Oct31==Dec25?