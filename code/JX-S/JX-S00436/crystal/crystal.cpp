#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500000],ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;i++)
    {
        long long temp=1,m2=m;
        for(int j=i-1;j>=0;j--)
        {
            m2-=a[i]-a[j];
            if(m2<0)
            {
                break;
            }
            temp++;
        }
        ans=max(ans,temp);
    }
    cout<<ans;
}
