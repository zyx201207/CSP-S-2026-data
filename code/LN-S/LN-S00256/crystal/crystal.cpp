#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    bool t;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>2&&a[i]-a[i-1]==a[i-1]-a[i-2])
        {
            continue;
        }
        t=false;
    }
    sort(a,a+n);
    int ans=0;
    if(t)
    {
        long long sum=0;
        int j=n-1,num=0;
        while(sum+a[n-1]-a[j]<=m&&j>=0)
        {
            sum+=a[n-1]-a[j];
            num++;
            j--;
        }
        ans=num;
    }
    for(int i=0;i<n;i++)
    {
        long long sum=0;
        int j=i,num=0;
        while(sum+a[i]-a[j]<=m&&j>=0)
        {
            sum+=a[i]-a[j];
            num++;
            j--;
        }
        ans=max(ans,num);
    }
    cout<<ans;
    return 0;
}
