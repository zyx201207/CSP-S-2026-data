#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N],s[N],ans;
long long cal(long long x){
    long long l=1,r=x;
    while(l<=r){
        long long mid=(l+r+1)/2;
        long long cnt=mid*a[x]-(s[x]-s[x-mid]);
    //    cout<<x<<" "<<mid<<" "<<cnt<<"   ";
        if(cnt<=m)l=mid+1;
        else r=mid-1;
    }
    return r;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,cal(i));
     //   cout<<ans;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}