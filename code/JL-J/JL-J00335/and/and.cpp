#include<bits/stdc++.h>
using namespace std;
long long a[100000032];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    long long maxn=INT_MIN;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(m==2)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i^j>=maxn)
                {
                    maxn=i^j;
                }
            }
        }
        cout<<maxn;
    }else if(m==n){
        long long ans=a[0];
        for(int i=1;i<n;i++)
        {
            ans=ans^a[i];
        }
        cout<<ans;
    }
}
