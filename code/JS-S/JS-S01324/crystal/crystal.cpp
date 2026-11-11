#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500005];
bool cmp(long long xx,long long yy){
    return xx<yy;
}
int Check(long long x){
    long long tar=a[x];
    long long sum=0;
    for(int i=1;i<=x;i++){
        sum=sum+tar-a[i];
        if(sum > m){
            return 0;
        }
    }
    if(sum<=m){
        return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    long long l=1,r=n;
    while(l<r){
        long long mid=l+((r-l)>>1);
        if(Check(mid) == 1){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
