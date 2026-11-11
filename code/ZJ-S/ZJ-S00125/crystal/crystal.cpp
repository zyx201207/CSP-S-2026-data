#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long ans=-1;
bool check(long long mid){
    long long cnt=0,ct=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=mid){
            ct++;
            cnt+=(mid-a[i]);
        }
    }
    if((cnt<=m)&&(ct>ans)){
        ans=ct;
        return 1;
    }else{
        return 0;
    }
}
int main(){
    ios::sync_with_stdio(NULL);
    cout.tie(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long mx=-1e12,mn=1e12;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    long long l=mn,r=mx;
    while(l<=r){
        long long mid=(l+r+1)>>1;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}