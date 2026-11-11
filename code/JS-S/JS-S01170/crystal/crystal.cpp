#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[514514],n,m;
bool check(int cur){
    int basum=0,needl=2e18;
    for(int i=0;i<cur;i++){
        basum+=a[i];
    }
    needl=(cur*a[cur-1])-basum;
    for(int i=cur;i<n;i++){
        basum-=a[i-cur];
        basum+=a[i];
        needl=min(needl,(cur*a[i])-basum);
    }
    return needl<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int l=0,r=n,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}
