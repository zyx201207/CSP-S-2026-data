#include <bits/stdc++.h>
using namespace std;

long long a[500005];
int n;
long long m;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int head=0;
    int maxans=-1;
    for(int i=1;i<n;i++)
    {
        if(m-(i-head)*(a[i]-a[i-1])>=0)
        {
            m-=(i-head)*(a[i]-a[i-1]);
            maxans=max(maxans,i-head+1);
        }
        else
        {
            m+=a[i-1]-a[head];
            head++;
            if(m-(i-head)*(a[i]-a[i-1])>=0)
            {
                m-=(i-head)*(a[i]-a[i-1]);
                maxans=max(maxans,i-head+1);
                continue;
            }
            m-=(i-head)*(a[i]-a[i-1]);
        }
    }
    cout<<maxans<<endl;
    return 0;
}

