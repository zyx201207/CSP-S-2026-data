#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+5;
long long a[N];
char c[N];
long long ans=0;
int nn=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        if(c[i]==c[nn])
        {
            a[nn]+=a[i];
        }
        else
        {
            nn+=1;
            c[nn]=c[i];
        }
    }
    if(nn%2==1)
    {
        for(int i=1;i<=nn/2+1;i++)
        {
            if(i!=nn/2+1)
            {
                if(c[i]==c[nn-i+1])
                {
                    ans+=abs(a[i]-a[nn-i+1]);
                }
                else
                {
                    ans+=min(a[i],a[nn-i+1]);
                    if(ans==a[i])
                    {
                        a[i+1]-=a[nn-i+1]-a[i];
                        ans+=a[nn-i+1]-a[i];
                    }
                    else
                    {
                        a[nn-i]-=a[i]-a[n-i+1];
                        ans+=a[i]-a[nn-i+1];
                    }
                }
            }
        }
        cout << ans;
    }
    else
    {
        for(int i=1;i<=nn/2;i++)
        {
            if(c[i]==c[nn-i+1])
            {
                ans+=abs(a[i]-a[nn-i+1]);
            }
            else
            {
                ans+=min(a[i],a[nn-i+1]);
                if(ans==a[i])
                {
                    a[i+1]-=a[nn-i+1]-a[i];
                    ans+=a[nn-i+1]-a[i];
                }
                else
                {
                    a[nn-i]-=a[i]-a[nn-i+1];
                    ans+=a[i]-a[nn-i+1];
                }
            }
        }
        cout << ans;
    }
    return 0;
}
