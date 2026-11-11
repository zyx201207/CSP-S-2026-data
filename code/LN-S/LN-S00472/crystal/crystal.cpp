#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans;
long long b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }

    long long sum=0;
    for(long long i=1;i<=n;i++){
        sum=b[i];
        for(long long j=i;j<=n;j++){
            sum+=b[j]*(j-i);

            if(sum<=m){
                ans=max(ans,j-i+1);
            }
        }

    }
    cout<<ans;
    return 0;
}
