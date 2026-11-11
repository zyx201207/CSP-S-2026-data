#include <bits/stdc++.h>
using namespace std;

long long n,m,ans=1;
long long a[500010];
long long sum[500010];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    long long j=1;
    for(long long i=1;i<=n;i++){
        while(j<i&&(i-j)*a[i]-sum[i-1]+sum[j-1]>m){
            j++;
        }
        ans=max(ans,i-j+1ll);
    }
    cout<<ans<<endl;
    return 0;
}
