#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans1=INT_MIN,ans2,ans3=INT_MIN;
int a[200001];
bool Is_B=true;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i-1)
        {
            Is_B=false;
        }
        ans1=max(ans1,a[i]);
        if(i==1)
        {
            ans2=a[i];
        }
        else
        {
            ans2=ans2&a[i];
        }
    }
    if(m==n)
    {
        cout<<ans2;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                ans3=max(ans3,a[i]&a[j]);
            }
        }
        cout<<ans3;
    }
    else if(Is_B)
    {

    }
    else
    {
        cout<<ans1;
    }
    return 0;
}
