#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long m,n,a[MAXN],l,r;
long long ans,sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    l=1,r=1;
    while(r<=n){
        long long jsum=(a[r]-a[r-1])*(r-l+1);
        if(sum+jsum<=m){
            ans=max(r-l+1,ans),sum+=jsum,r++;
        }else{
            sum-=(a[r]-a[l++]);
        }
        if(l>r) r++;
    }
    cout<<ans+1;
    return 0;
}
