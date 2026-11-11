#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int a[500005];
    int n;
    int m;
    int cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(m!=0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]<a[i+1]&&m!=0)
            {
                a[i]++;
            }
            m--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]=a[1])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
