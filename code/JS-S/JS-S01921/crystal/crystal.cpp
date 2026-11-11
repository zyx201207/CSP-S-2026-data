#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n;
long long m;
long long a[MAXN];
long long s1[MAXN];
long long s2[MAXN];
bool check(int mid){
    long long paid=0;
    for(int i=1;i<=n-mid+1;i++){
        long long paid=s1[i+mid-1]-s1[i]-(a[i+mid-1]-a[i])*(i-1);
        if(paid<=m){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    s2[1]=0;
    s1[0]=0;
    for(int i=2;i<=n;i++)s1[i]=s1[i-1]+(a[i]-a[i-1])*(i-1);
    for(int i=1;i<=n;i++)s2[i]=s2[i-1]+a[i];
    int l=1,r=n,mid,ans=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
