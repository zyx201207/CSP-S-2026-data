#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long n,ans;
unsigned long long m;
bool check(long long x){
    unsigned long long sum=0;
    long long maxx=-1e18;
    for(int i=1;i<=x;i++)sum+=abs(a[i]-a[x]);
    return sum<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    long long l=1,r=n;
    while(l<r){
        long long mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else r=mid-1;
    }
    cout<<ans;
    return 0;
}
/*5 5
1 2 4 8 9*/
/*5 8
-3 -1 2 2 7*/
