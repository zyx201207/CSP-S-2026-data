#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[999999],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int cnt=0,mm=m;
    for(int i=2;i<=n;i++)
    {
        cnt=0,mm=m;
        for(int j=i-1;j>=1;j--)
        {
            if(mm-(a[i]-a[j])>=0)
            {
                mm-=(a[i]-a[j]);
                cnt++;
                if(cnt>ans)
                {
                    ans=cnt;
                }
            }
            else
            {
                break;
            }
        }
    }
    ans++;
    cout<<ans;
    return 0;
}