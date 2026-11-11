#include<bits/stdc++.h>
using namespace std;
int a[50005],sum;
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

    int num=1;
    for(int i=n-1;i>=0;i--)
    {
        if(m>0)
        {
            a[i]=a[n];
            m-=num;
        }
        num++;
        cout<<m<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[n]) sum++;
    }
    cout<<sum;
    return 0;
}
