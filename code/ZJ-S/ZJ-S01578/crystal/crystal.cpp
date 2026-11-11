#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int N=5e5+5;
int n,ans;
ll m,a[N],sum[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1, j=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        while(j<i&&a[i]*(i-j+1)-sum[i]+sum[j-1]>m) j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans<<"\n";
    return 0;
}