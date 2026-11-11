#include<bits/stdc++.h>
using namespace std;
int a[200000],n,m,maxa;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("travel.in",r,stdin);
    freopen("travel.out",w,stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    maxa=a[0];
    for(int i=1;i<m;i++)
    {
        maxa&=a[i];
    }
    cout<<maxa;
    return 0;
}
