#include<bits/stdc++.h>
using namespace std;
long long a[1000004];
long long n,m;
long long sum[1000004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    long long ans=0;
    long long j=0;
    for(int i=1;i<=n;i++){
        while(a[i]*(i-j)-(sum[i]-sum[j])>m){
            j++;
        }
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}
