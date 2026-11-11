#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char s[200005];
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
    }
    int l=1,r=n;
    while(l<r)
    {
        if(s[l]==s[r] && a[l]!=a[r])
        {
            ans+=min(a[l],a[r]);
            if(a[l]<a[r])
            {
                a[r]-=a[r]-a[l];
                l++;
            }
            else
            {
                a[l]-=a[l]-a[r];
                r--;
            }
        }
        else if(s[l]!=s[r] && a[l]==a[r])
        {
            ans+=a[l];
            l++;
            r--;
        }

        else if(s[l]!=s[r] && a[l]!=a[r])
        {
            ans+=min(a[l],a[r]);
            if(a[l]<a[r])
            {
                a[r]-=a[r]-a[l];
                l++;
            }
            else
            {
                a[l]-=a[l]-a[r];
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
