#include<bits/stdc++.h>
using namespace std;
int n,ans,ti;
long long m,a[500005],s[500005];
bool check(int mid){
    return a[ti]*(ti-mid+1)-(s[ti]-s[mid-1])>m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        int l=1,r=i;
        ti=i;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid)) l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
