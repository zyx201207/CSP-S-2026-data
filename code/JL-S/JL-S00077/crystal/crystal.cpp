#include<bits/stdc++.h>
using namespace std;
bool flag=1;
long long n,m;
long long a[500005],pre[500005];
bool check(long long x){
    for(int i=1;i<=n-x+1;i++){
        long long sum=0;
        for(int j=1;j<=x-1;j++){
            sum+=j*pre[i+j];
            if(sum>m){
                break;
            }
        }
        if(sum<=m){
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
            flag=0;
            break;
        }
    }
    if(flag){
        long long s=a[2]-a[1];
        long long k=0,ans=0;
        for(int i=0;i<=n;i++){
            k+=i;
            if(s*k<=m){
                ans++;
            }
            else{
                break;
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=2;i<=n;i++){
        pre[i]=a[i]-a[i-1];
    }
    long long l,r,ans,mid;
    l=1;
    r=n;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
