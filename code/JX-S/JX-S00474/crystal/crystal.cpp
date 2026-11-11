#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],d[N],ans=1;
ll s1[N],s2[N];
//s1[i]=d[1]+d[2]+d[3]+...+d[i]
//s2[i]=s1[1]+s1[2]+s1[3]+...+s1[i]
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1])continue;
        d[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;i++){
        s1[i]=s1[i-1]+d[i];
        s2[i]=s2[i-1]+s1[i];
    }
    //for(int i=1;i<=n;i++){
    //    cout<<s1[i]<<" ";
    //}
    //cout<<'\n';
    //for(int i=1;i<=n;i++){
    //    cout<<s2[i]<<" ";
    //}
    //cout<<'\n';
    for(ll i=2;i<=n;i++){
        ll l=1,r=i-1,mid,cnt=0;
        while(l<=r){
            mid=l+(r-l)/2;
            ll sum=(i-mid+1)*s1[i]-(s2[i]-s2[mid-1]);
            //for(int j=mid;j<=i;j++){
                //sum+=s1[i]-s1[j];
            //}
            if(/*s2[i]-s2[mid]-(a[i]-a[mid])*(mid-1)<=m*/sum<=m){
                cnt=(i-mid+1);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/
