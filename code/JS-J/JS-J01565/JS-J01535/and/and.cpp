#include<bits/stdc++.h>
using namespace std;
int ans=INT_MIN;
int n,m;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1);
    if(m==1)
    {
        cout<<a[n];
        return 0;
    }
    if(m==n)
    {
        for(int i=2;i<=n;i++)
        {
            a[i]=a[i]&a[i-1];
        }
        cout<<a[n];
        return 0;
    }
    if(m==2)
    {
        int maxn=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j!=i)
                {
                    int x=a[i]&a[j];
                    maxn=max(x,maxn);
                }
            }   
        }
        cout<<maxn;
        return 0;
    }
    else{
        cout<<a[n-m+1];
    }
    return 0;
}