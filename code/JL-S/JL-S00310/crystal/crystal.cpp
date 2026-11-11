#include<bits/stdc++.h>
using namespace std;
long long a[10005],b[10005];
long long s=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=1;i>=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i+1]-a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[1]==a[i+1])
        {
           s++;
        }
        else if(b[i]==b[i+1])
        {
            s+=m/b[1];
        }
    }
    cout<<s;
}
