#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mid,l,r;
ll m;
ll n;
ll sm[600010];
ll a[600010];
bool check(ll k){
    bool flg=false;
    for(int i=k;i<=n;i++){
        if(a[i]*k-(sm[i]-sm[i-k])<=m){
            flg=true;
        }
    }
    return flg;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(ll i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
sm[1]=a[1];
for(ll i=1;i<=n;i++){
    sm[i]=a[i]+sm[i-1];
}
r=n;
l=0;
while(l<r){
if(check(mid)){
    l=mid+1;
mid=(l+r-1)/2;
}
else{
    r=mid-1;
mid=(l+r-1)/2;
}
}
cout<<mid;
return 0;
}
