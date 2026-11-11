#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000007
long long n,m,a[MAXN],S[MAXN],ans,l,r,mid;
bool check(long long x){
    long long cnt=0,s=0;
    for(int i=0;i<x;i++)s+=S[i]*(i+1),cnt+=S[i];
    if(s<=m)return 1;
    for(int i=0;i<n-1;i++){
        if(i+x>=n-1)break;
        //cout<<s<<' '<<cnt<<endl;
        s-=cnt,s+=S[i+x]*x;cnt-=S[i],cnt+=S[i+x];
        //cout<<s<<' '<<cnt<<endl;
        if(s<=m)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++)S[i]=a[i+1]-a[i];
    l=1,r=n;
    while(l<=r){
        mid=l+r>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans+1;
    return 0;
}

