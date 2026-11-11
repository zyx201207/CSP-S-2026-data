#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],sum[50000005];
bool check(int y,int x){
    long long tot=((y-x+1)*a[y])-(sum[y]-sum[x-1]);
    if(tot<=m)return true;
    else return false;
}
int ans=0;
int main(){
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
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(r-l)/2+l;
            if(check(i,mid))r=mid-1;
            else l=mid;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
