#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5+5;
int a[N+5],s[N+5];
int n,m;
int ans=0;
void query(int x){
    int l=1,r=x;
    int an=x;
    while (l<=r){
        int mid=(l+r)>>1;
        if ((x-mid+1)*a[x]-(s[x]-s[mid-1])<=m){
            an=mid;
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    // cout<<an<<" ";
    ans=max(ans,x-an+1);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        query(i);
    }
    // for (int i=1;i<=n;i++){
    //     cout<<s[i];
    // }
    cout<<ans<<"\n";
    return 0;
}