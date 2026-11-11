#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;

long long n,m,a[N],s,ans=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    //for(int i=1;i<=n;i++)
    //{
        //sum+=((a[i]-a[i-1])*(i-1));
        //if(m<sum)
      //  {
      //      cout<<i-1;
       //     return 0;

      //  }
  //  }


    long long l=1,r=1;
    while(l<=r&&r<n)
    {
        r++;
        s+=(r-l)*(a[r]-a[r-1]);
        if(s<=m) ans=max(ans,r-l+1);
        else s-=(a[r]-a[l]),l++;
        //cout<<l<<' '<<r<<' '<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}

