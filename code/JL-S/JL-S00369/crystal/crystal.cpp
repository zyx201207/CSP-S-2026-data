#include<bits/stdc++.h>
using namespace std;
long long  a[1000001];
long long  n,m;
bool check(long long u){
    long long l=1,r=1;
    long long nd=0;
    for(long long i=2;i<=n;i++){
    if(i<=u){
        nd+=(r-l+1)*(a[r+1]-a[r]);
        r++;
    }
    else{
        nd-=a[r]-a[l];
        l++;
        nd+=(r-l+1)*(a[r+1]-a[r]);
        r++;

    }
    if(nd<=m&&r-l+1==u)
            return 1;
   // cout<<l<<" "<<r<<" "<<nd<<"\n";
    }
    return 0;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
for(long long i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
long long l=1,r=n,ll=-1,rr=-1;
while(l<r){
        if(ll==l&&rr==r)
        break;
        ll=l;
        rr=r;
       // cout<<l<<" "<<r;
    long long mid=(l+r)/2;
    if(check(mid))
    l=mid;
    else
    r=mid-1;
   // cout<<"\n";
}
cout<<l;
return 0;
}
