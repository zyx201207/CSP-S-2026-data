#include <bits/stdc++.h>
using namespace std;
__int128 n,m,i,j,k,a[500009],b[500009],ans;
bool ch(__int128 x){
    __int128 i,y;
    for(i=x;i<=n;i++){
        y=b[i]-b[i-x];
        if(a[i]*x-y<=m)return 1;
    }
    return 0;
}
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long nn,mm,abc;
    cin>>nn>>mm;
    n=nn;m=mm;
    for(i=1;i<=n;i++){
        cin>>abc;
        a[i]=abc;
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    __int128 l=1,r=n,mid;
    while(l<=r){
        mid=l+(r-l)/2;
//        cout<<l<<" "<<r<<" "<<ch(mid)<<"\n";
        if(ch(mid)==1){
            ans=max(ans,mid);
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    long long anss;
    anss=ans;
    cout<<anss;
    return 0;
}
