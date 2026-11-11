#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500002];
long long s[300002];
long long ans[300002];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        s[a[i-1]]--;
        for(int j=n;j>=i;j--)
        {
            ans[a[j]]++;
            if(s[a[j]]%2==0)
            {
                break;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
