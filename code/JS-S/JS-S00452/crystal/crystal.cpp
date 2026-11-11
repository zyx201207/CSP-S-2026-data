#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long n,m;
long long b[N];
bool check(long long mid){
    for(int i=1;i<=n;i++){
        if(i-1-mid<0) continue;
        if(a[i]*mid-(b[i-1]-b[i-1-mid])<=m){

            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i =1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    long long l=0,r=n;
    long long ans=0;
    while(l<=r){
        long long mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans+1;
    return 0;
}
