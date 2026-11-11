#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[3000000];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(m==2)
    {
        int maxs=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((a[i]&a[j])>maxs)
                {
                    maxs=(a[i]&a[j]);
                }
            }
        }
        cout<<maxs;
        return 0;
    }
    if(m==1)
    {
        sort(a,a+n,cmp);
        cout<<a[0];
        return 0;
    }
    if(m==n)
    {
        int ans=a[0];
        for(int i=1;i<n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
