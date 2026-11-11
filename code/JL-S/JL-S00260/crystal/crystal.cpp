#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long  n,m,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    /*for(long long i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;*/
    long long mm,maxv=INT_MIN;
    for(long long w=n;w>=1;w--)
    {

        mm=m;
        long long ans=0;
        for(long long i=1;w-i>=1;i++)
        {
            if(w-i<0||a[w]-a[w-i]>mm)
                break;
            if(a[w]-a[w-i]<=mm)
            {
                mm=mm-(a[w]-a[w-i]);
                //cout<<a[w]<<" - "<<a[w-i]<<" == "<<a[w]-a[w-i]<<" "<<mm<<endl;
                ans++;
            }
        }
        ans++;
        if(ans>maxv)
            maxv=ans;
       // cout<<ans<<" "<<maxv<<endl;
    }
    cout<<maxv;
    return 0;
}
