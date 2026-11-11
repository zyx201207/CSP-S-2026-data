#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,sum=0,a[100000];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=m;i++)
    {
        if(i==1)
        {
            sum=a[i];
        }
        else
        {
            sum&=a[i];
        }
    }
    cout<<sum;
}
