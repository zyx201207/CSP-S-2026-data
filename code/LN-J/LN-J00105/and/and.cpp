#include<bits/stdc++.h>
using namespace std;
int a[2000010];
bool null(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,s=0,s1,s2,s3,ma=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,null);
    s1=a[0];
    s2=s1;
    for(int i=1;i<n;i++)
    {
        s2=s2&a[i];
    }
    for(int i=0;i<n;i++)
    {

        for(int j=i+1;j<n;j++)
        {
            ma=max(a[i]&a[j],ma);
        }
    }
    if(n==m)
    {
        cout<<s2;
    }
    if(m==1)
    {
        cout<<s1;
    }
    if(m==2)
    {
        cout<<ma;
    }
    return 0;
}
