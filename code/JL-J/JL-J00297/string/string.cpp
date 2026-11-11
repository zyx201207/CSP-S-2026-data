#include<bits/stdc++.h>
using namespace std;
long long ans=0;
struct CCC
{
    long long c;
    char b;
}a[200020];
void BBB(int x,int y)
{
    if(x==y)
    {
        return ;
    }
    if(a[x].b!=a[y].b)
    {
        if(a[x].c>=a[y].c)
        {
            ans+=a[y].c;
            if(a[x].c>a[y].c)
            {
                a[x].c-=a[y].c;
                if(y-1==x)
                {
                    return ;
                }
                BBB(x,y-1);
            }
            else
            {
                if(y-1==x)
                {
                    return ;
                }
                BBB(x+1,y-1);
            }
        }
        else
        {
            a[y].c-=a[x].c;
            ans+=a[x].c;
            if(x+1==y)
            {
                return ;
            }
            BBB(x+1,y);
        }
    }
    else
    {
        if(a[x].c>a[y].c)
        {
            a[x].c-=a[y].c;
            if(y-1==x)
            {
                return ;
            }
            BBB(x,y-1);
        }
        else if(a[x].c<a[y].c)
        {
            a[y].c-=a[x].c;
            if(x+1==y)
            {
                return ;
            }
            BBB(x+1,y);
        }
        else
        {
            if(y-1==x)
            {
                return ;
            }
            BBB(x+1,y-1);
        }
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    if(n==1)
    {
        cout<<0;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i].c>>a[i].b;
    }
    BBB(0,n-1);
    cout<<ans;
    return 0;
}
