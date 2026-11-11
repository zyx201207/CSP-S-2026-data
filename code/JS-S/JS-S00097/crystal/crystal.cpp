#include "bits/stdc++.h"
using namespace std;
const int N=5e5+5;
#define int long long
long long n,m,ans;
long long a[N],c[N];

bool check(long long x){
    for(int i=n;i>=x;i--){
        //cout<<"try"<<i<<" "<<x<<endl;
        if((x-1)*a[i]-c[i-1]+c[i-x]<=m){
           // cout<<"pass "<<i<<" "<<x<<" "<<c[i]-c[i-x]<<endl<<endl;
            return 1;
        }

        //cout<<"unpass "<<i<<" "<<x<<endl<<endl;
    }
    return 0;
}

bool cmp(int x,int y){
    return x<y;
}

signed main()
{

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    c[1]=a[1];
    for(int i=2;i<=n;i++)
        c[i]=c[i-1]+a[i];
   // for(int i=1;i<=n;i++)
      //  cout<<c[i]<<' ';
    long long l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<ans;
    return 0;
}
