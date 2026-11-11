#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long ans;
long long tmp;
long long idx;
long long res=-1;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(long long i=n;i>=1;i--){
        ans=1;
        tmp=m;
        idx=i-1;
        while(tmp-(a[i]-a[idx])>=0 && idx>=1){
            tmp-=(a[i]-a[idx]);
            idx--;
            ans++;
        }
        res=max(res,ans);
    }
    cout<<res;
}
