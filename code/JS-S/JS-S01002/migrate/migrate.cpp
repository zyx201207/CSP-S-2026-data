#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n,d,ans=0;
    cin>>n>>d;
    vector<pair<long long,int>>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=0;
    }
    for(int i=1;i<a[n-1].first/d;i++)
    {
        a[i].second++;
        for(int j=i*d+1;j<(i+1)*d;j++) if(j<=n-1)
                for(int k=0;k<n;k++)
                    if(a[k].first==j)
                    {
                        a[k].second++;
                        break;
                    }
    }
    for(int i=a[n-1].first/d;i>=0;i--)
    {
        for(int j=(i+1)*d-1;j>=i*d;j--) if(j>=1)
                for(int k=0;k<n;k++)
                    if(a[k].first==j)
                    {
                        a[k].second++;
                        break;
                    }
    }
    for(int i=n-1;i>=n/2+n%2;i--) if(a[i].second==2) ans++;
    cout<<ans<<endl;
}
int main()
{
    freopen("migrate","r",stdin);
    freopen("migrate","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
