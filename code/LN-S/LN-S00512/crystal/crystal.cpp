#include<bits/stdc++.h>
using namespace std;
long long c[500010],qian[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long a,b,ans = 0;
    cin>>a>>b;
    for(int i = 1;i<=a;i++)
    {
        cin>>c[i];
    }
    sort(c+1,c+a+1);
    for(int i = 1;i<=a;i++)
    {
        qian[i]=qian[i-1]+c[i];
    }
    for(int i = 1;i<=a;i++)
    {
        long long l = 0,r = i-1;
        while(l<r)
        {
            long long mid = (l+r+1)/2;
            if(c[i]*mid-qian[i-1]+qian[i-mid-1]<=b)
            {
                l=mid;
            }
            else
            {
                r=mid-1;
            }
        }
        ans=max(ans,l+1);
    }
    cout <<ans;
    return 0;
}
