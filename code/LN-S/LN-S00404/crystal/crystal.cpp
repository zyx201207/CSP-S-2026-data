#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans;
long long a[500005];
int erfenchazhao(long long x){
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(a[mid]<=x&&a[mid+1]>x){
            return mid;
        }else if(a[mid]<=x&&a[mid+1]<=x){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return 0;
}
long long chec(long long goa){
    int index=erfenchazhao(goa);
    int uuse=m,cnt=0;
    while(goa-a[index]<=uuse&&index>0){
        uuse-=(goa-a[index]);
        index--;
        cnt++;
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        ans=max(chec(a[i]),ans);
    }
    cout<<ans;
    return 0;
}
