#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,maxans=-1;;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n>10000){
        long long sum=0,b=a[n]-a[n-1],ans=0;
        for(long long i=n-1;i>=1;i--){
            sum+=(n-i);
            if((sum*b)>m){
                break;
            }
            ans++;
        }
        cout<<ans;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        long long sum=0,ans=1;
        for(long long j=i-1;j>=1;j--){
            if((a[i]-a[j])+sum>m){
                break;
            }
            ans++;
            sum+=(a[i]-a[j]);
        }
        maxans=max(maxans,ans);
    }
    cout<<maxans;
    return 0;
}
