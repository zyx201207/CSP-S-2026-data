#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int ned=0,l=1,r=1,ans=0;
    a[1]=1;
    for(int i=2;i<=n;i++){

        if(a[i]==a[i-1]) r++;
        else{
            if(ned+(r-l+1)*(a[i]-a[i-1])<=m){
                r++;
                ned+=(r-l+1)*(a[i]-a[i-1]);
            }
            else{
                while(ned+(r-l+1)*(a[i]-a[i-1])>m){
                    ned-=(a[i-1]-a[l]);
                    l++;
                }
                r++;
                ned+=(r-l+1)*(a[i]-a[i-1]);
            }
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
}

