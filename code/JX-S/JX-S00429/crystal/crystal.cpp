#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,w[500005],sum[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    n--;
    for(int i=1;i<=n;i++)w[i]=a[i+1]-a[i];
    for(int i=1;i<=n;i++)sum[i]=w[i]+sum[i-1];
    long long l=1,r=1,num=w[1];
    while(l<=r&&r<=n){
        if(num<=m){
            ans=max(ans,r-l+1);
            r++;
            num+=w[r]*(r-l+1);
        }
        else{
            if(r>l){
                num-=sum[r]-sum[l-1];
                l++;
            }
            else{
                r++;
                num+=w[r]*(r-l+1);
            }
        }
    }
    ans++;
    cout<<ans;
    return 0;
}
