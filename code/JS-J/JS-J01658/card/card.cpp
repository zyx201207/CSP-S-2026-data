#include <bits/stdc++.h>
using namespace std;
int a[100005];
int y[666666];
int m[300005];
int s;
bool check(int x,int r)
{
    
    for(int i=1;i<=r;i++)
    {
        if(y[i]==x)
        {
            s=i;
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int T=1;
    int r=0;
    while(T++)
    {
        if(T>n)
        {
            break;
        }
        r=0;
        for(int i=T;i<=n;i++)
        {
            if(check(a[i],r)==true)
            {
                r=s;
            }
            else{
                r++;
                y[r]=a[i];
            }
        }
        for(int i=1;i<=r;i++)
        {
            int h=y[i];
            m[h]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<m[i];
    }
}