#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],s[500005];
long long m,ans;
bool cmp(long long x,long long y){
    return x<=y;
}
long long check(long long x){
    long long sum=1e18;
    for(int i=1;i+x-1<=n;i++){
        sum=min(sum,x*a[i+x-1]-(s[i+x-1]-s[i-1]));
    }
    return sum;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    long long l=1,r=n;
    while(l<=r){
        long long mid=(l+r)/2;
        if(check(mid)>m)r=mid-1;
        else{
            l=mid+1;
            ans=mid;
        }
    }
    cout<<ans<<endl;
    return 0;
}
