#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[1000005],s[1000005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=1;
    while(r<=n){
        if(((r+1-l+1)*a[r+1])-s[r+1]+s[l-1]<=m){
            r++;
        }
        else l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
