#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=1,r=2,ans=1,cnt=2,t=m;
    for(;l<=r&&r<=n;r++,cnt++){
        long long cost=(r-l)*(a[r]-a[r-1]);
        if(t>=cost){
            t-=cost;
            ans=max(ans,cnt);
        }else{
            while(t<cost&&l<r){
                t+=a[r-1]-a[l];
                l++;
                cnt--;
                cost=(r-l)*(a[r]-a[r-1]);
            }
            t-=cost;
        }
    }
    cout<<ans;
    return 0;
}
