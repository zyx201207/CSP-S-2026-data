#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,a[500005],p[500005],l=1,r=1,cnt,ans;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
    }
    while(r<=n){
        if(cnt<=m){
            ans=max(ans,r-l+1);
            r++;
            cnt=a[r]*(r-l+1)-p[r]+p[l-1];
        }else{
            cnt-=a[r]-a[l];
            l++;
        }
    }
    cout<<ans;
    return 0;
}