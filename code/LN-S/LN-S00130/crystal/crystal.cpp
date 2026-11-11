#include <bits/stdc++.h>
using namespace std;
int a[100000001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int p=n/2;
    int step=0;
    int maxx=-999;
    while(m!=0)
    {
        for(int i=p;i>=p;i--)
        {
            m=m-a[p]+a[i];
            if(m>=0)
            {
                step++;
            }
        }
        if(maxx<step) maxx=step;
        step=0;
        for(int i=p;i<=n;i++)
        {
            m=m-a[i]+a[p];
            step++;
        }
        if(m>=0)
        {
            step++;
        }
        if(maxx<step)
        {

            maxx=step;
        }
        m=0;
    }
    cout<<maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
