#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long m;
bool check(int x){
    long long sum=0;
    for(int i=1;i<=x;i++){
        sum+=a[x]-a[i];
        if(sum>m) return 0;
    }
    return 1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
