#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=1;
    cin>>n>>m;
    vector<long long>a(n+2);
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=-1e18;
    a[n+1]=1e18;
    sort(a.begin(),a.end());
    int l=n/2+1,r=n/2+1;
    while(1)
    {
        if(a[l]-a[l-1]<=a[r+1]-a[r])
        {
            m=m-(a[l]-a[l-1]);
            if(m<0) break;
            ans++;
            a[l-1]=a[l];
            l--;
        }
        else
        {
            m=m-(a[r+1]-a[r])*(r-l+1);
            if(m<0) break;
            ans++;
            r++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
