#include<bits/stdc++.h>
using namespace std;
const int kMaxN=5e5+5;
long long n,m,a[kMaxN];
bool C(long long mid){
    long long sum=0;
    for(int i=1;i<mid;i++) sum+=a[i];
    for(int l=1,r=mid;r<=n;l++,r++){
        if(a[r]*(mid-1ll)-sum<=m) return true;
        sum-=a[l],sum+=a[r];
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long lef=1,rig=n;
    while(lef<rig){
        long long mid=(lef+rig+1)/2;
        C(mid)?lef=mid:rig=mid-1;
    }
    cout<<lef;
    return 0;
}