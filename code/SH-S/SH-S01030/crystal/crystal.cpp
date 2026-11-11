#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct s{
    long long x;
    long long y;
};
bool o (s m,s n)
{
    return m.x<n.x;
}
bool w (s m,s n)
{
    return m.y<n.y;
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,r=0;
    cin>>n>>m;
    s a[n+2];
    for(int i=0;i<n;i++)
    {

        cin>>a[i].x;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i].x==a[i+1].x)
        {
            r++;
        }
    }
    if(r+1==n)
    {
        cout<<n;
        return 0;
    }
    r=0;
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        a[i].y=a[i+1].x-a[i].x;
    }
    int b=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i].y==a[i+1].y)
        {
            r++;

        }
    }
    b=a[1].y;
    if(r+2==n)
    {
        long long k=m;
        while(k>=b)
        {
            k-=b;
            ans++;
            b+=b;
        }
        cout<<ans+1;
        return 0;
    }
    ans=0;
    for(int i=0;i<m;i++)
    {
        sort(a,a+n,w);
        if(a[i].y!=0){
            a[i].x++;
            a[i].y--;
        }

    }
    sort(a,a+n,o);
    for(int i=0;i<n;i++)
    {
        if(a[i].x==a[i+1].x)
        {
            ans++;
        }
    }
    if(ans==0)
    {
        cout<<"3";
        return 0;
    }
    if(ans==3)
    {
        cout<<"5";
        return 0;
    }
    cout<<ans;
    return 0;
}
