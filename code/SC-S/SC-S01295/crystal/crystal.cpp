#include<bits/stdc++.h>
#define int long long

using namespace std;


const int N=5e5+100;

int n,m;
int a[N],s[N];
int ans;

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=n,j=n;i;i--)
    {
        while(a[i]*(i-j+1)<=s[i]-s[j-1]+m && j)
            j--;

        if(j==0)
        {
            ans=max(ans,i);
            break;
        }
        ans=max(ans,i-j);
    }
    cout<<ans<<endl;
    return 0;
}
