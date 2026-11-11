#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m;
long long a[500005];
int ans=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int need=0,j=0;
    for(int i=1;i<n;i++)
    {
        need+=(i-j)*(a[i]-a[i-1]);
        if(need>m)
        {while(need>m)
            {
                j++;
                need-=a[i]-a[j-1];
            }
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}