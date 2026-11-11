#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int a[maxn];
int n,m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,now=0,sum=0,ans=1;
    for(int i=2;i<=n;i++){
        now+=a[i]-a[i-1];
        sum+=(i-l)*(a[i]-a[i-1]);
        while(sum>m){
            sum-=(a[i]-a[l]);
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
