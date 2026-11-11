#include<bits/stdc++.h>
#define int long long
#define ln "\n"
using namespace std;
const int N=5e5+10;
int a[N];
int cnt[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=1;
    int j=1;
    for(int i=2;i<=n;i++)
    {
        cnt[i]=cnt[i-1]+(a[i]-a[i-1])*(i-1);
        int x=cnt[i]-cnt[j-1]-(j-1)*(a[j]-a[i-1]);
        while(x>m&&i>=j)
        {
            j++;
            x=cnt[i]-cnt[j-1]-(j-1)*(a[j]-a[i-1]);
        }
        if(x<=m) ans=max(ans,i-j+1);
    }
    cout<<ans<<ln;
    return 0;
}