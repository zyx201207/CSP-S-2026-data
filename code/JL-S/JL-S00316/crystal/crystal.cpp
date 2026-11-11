#include<bits/stdc++.h>
using namespace std;
int n;
int a[500010];
int m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int k=1;
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        m-=k*(a[i+1]-a[i]);
        if(m<0)
        {
            break;
        }
        k++;
        ans++;
    }
    if(ans==1)
    {
        cout<<0;
    }
    else
    {
        cout<<ans;
    }
    return 0;
}

