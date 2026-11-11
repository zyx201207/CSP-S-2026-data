#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    long long cnt=0;
    long long ans=0;
    for(long long l=1,r=1;r<=n;r++){
        long long tmp=cnt+1ll*(r-l)*(a[r]-a[r-1]);
        if(tmp>m){
            while(tmp>m&&l<r){
                tmp-=(a[r]-a[l]);
                l++;
            }
        }
        cnt=tmp;
        ans=max(ans,r-l+1ll);
    }
    cout<<ans;
    return 0;
}
