#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==2)
    {
        if(a[2]-a[1]<=m)
        {
            cout<<2;
        }
        else
        {
            cout<<1;
        }
        return 0;
    }
    int x=abs(a[2]-a[1]),s;
    for(int i=1;i<=n;i++)
    {
        if(i/2.0*(i+1)>1.0*m/x)
        {
            s=i;
            break;
        }
    }
    if(s>n)
    {
        cout<<n;
    }
    else
    {
        cout<<s;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
