/*#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    bool isA=true;
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            isA=false;
            break;
        }
    }
    if(isA){
        int sum=0,x=0;
        for(int i=1;i<=n;i++){
            sum+=i;
            if(sum>m)break;
            x++;
        }
        cout<<x+1;
        return 0;
    }
    bool isB=true;
    int p=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=p){
            isB=false;
            break;
        }
    }
    if(isB){
        int sum=0,x=0;
        for(int i=1;i<=n;i++){
            sum+=i;
            if(sum*p>m)break;
            x++;
        }
        cout<<x+1;
        return 0;
    }
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if((j-i+1)*a[j]-(sum[j]-sum[i-1])<=m)ans=max(ans,j-i+1);
    cout<<ans;
    return 0;
}
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],ans;
bool check(int x){
    int mn=1e18;
    for(int i=x;i<=n;i++){
        mn=(mn<(a[i]*x-sum[i]+sum[i-x])?mn:(a[i]*x-sum[i]+sum[i-x]));
    }
    return mn<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=0,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))l=mid+1,ans=max(ans,mid);
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
