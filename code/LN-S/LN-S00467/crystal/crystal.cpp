#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1000005],ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll b=m,j=n,aans=0;
    for(int i=n;i>=1;)
    {
        while(b-(a[i]-a[j])>=0)
        {
            aans++;
            b=b-a[i]+a[j];
            j--;
            if(j<=0)break;
        }
        ans=max(ans,aans);
        i--;
        b=b+(a[i+1]-a[i])*(aans-1);
        aans--;
    }
    cout<<ans;
    return 0;
}
