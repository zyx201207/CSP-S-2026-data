#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
    int n,m,maxn=0;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    if(m==2)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                maxn=max(maxn,a[j]&a[j+1]);
            }

        }
        cout<<maxn;
    }
    else if(m==1)
    {
        cout<<0;
    }
    return 0;
}
