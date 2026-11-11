#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    int a1,a2,a3,a4,an;
    cin>>a1>>a2>>a3>>a4>>an;
    int day;
    for(int i=1;i<=n;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            cout<<j;
        }
        day += 1;
        m++;
        if(m==n)
        {
            cout<<day;
            return 0;
        }
    }
    return 0;
}
