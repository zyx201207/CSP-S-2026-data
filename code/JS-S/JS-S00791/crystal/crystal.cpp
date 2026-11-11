#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int j=1,sum=a[1],ans=1;
    for(int i=2;i<=n;i++){
        sum+=a[i];
        while(j<i&&a[i]*(i-j+1)-sum>m)
            sum-=a[j++];
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}