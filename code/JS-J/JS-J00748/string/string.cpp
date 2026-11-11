#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int a[n+2];
    char c[n+2];
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        cin >> c[i];
    }
    long long sum=0;
    int l=1,r=n;
    int la=a[l],ra=a[r],minn=0;
    while(l<r)
    {
        minn=min(la,ra);
        if(c[l]!=c[r]) sum+=minn;
        if(minn==la)
        {
            l+=1;
            a[r]-=minn;
            if(a[r]==0) r-=1;
        }
        else
        {
            r-=1;
            a[l]-=minn;
        }
        la=a[l],ra=a[r];
    }
    cout << sum;
    return 0;
}
