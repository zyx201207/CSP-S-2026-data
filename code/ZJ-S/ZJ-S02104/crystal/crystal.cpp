#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
void solve()
{
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long st=0,num=1,ans=0;
    for(long long i=0;i<n-1;i++)
    {
        m-=(num)*(a[i+1]-a[i]);
        if(m<0)
        {
            while(m<0)
            {
                m+=(a[i+1]-a[st]);
                st++,num--;
            }
        }
        num++;
        ans=max(ans,num);
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    solve();
    return 0;
}