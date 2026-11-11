#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=1,sum=0;
    cin>>n>>m;
    long long a[n+10]={0};
    long long h[n+10]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    for(int i=2;i<=n;i++){//a[i] this time choose
        sum=0;
        for(int q=i-1;q>=1;q--){
            sum+=a[i]-a[q];
            if(sum<=m){
                h[i]++;
            }
        }
    }
    ans=-1e9;
    for(int i=1;i<=n;i++){
        ans=max(ans,h[i]);
    }
    cout<<ans+1;
    return 0;
}
