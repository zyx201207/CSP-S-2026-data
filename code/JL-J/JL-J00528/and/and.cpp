#include<bits/stdc++.h>
using namespace std;
int a[10000010];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,ma=-1;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    ma=max(ma,a[i]);
}
if(m==1)
{
    cout<<ma;
    return 0;
}
ma=-1;
if(m==2)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                ma=max(ma, a[i] & a[j] );
            }
        }
    }
}
if(m==3)
{
    for(int i1=1;i1<=n;i1++)
    {
        for(int i2=1;i2<=n;i2++)
        {
            if(i2==i1)
            {
                continue;
            }
            for(int i3=1;i3<=n;i3++)
            {
                if(i3!=i1&&i2!=i1&&i2!=i3)
                {
                    ma=max(ma, a[i1] & a[i2] & a[i3]);
                }
            }
        }
    }
}
if(m==4)
{
    for(int i1=1;i1<=n;i1++)
    {
        for(int i2=1;i2<=n;i2++)
        {
            if(i2==i1)
            {
                continue;
            }
            for(int i3=1;i3<=n;i3++)
            {
                if(i3==i2)
                {
                    continue;
                }
                for(int i4=1;i4<=n;i4++)
                {
                    if(i1!=i2&&i1!=i3&&i1!=i4&&i2!=i3&&i2!=i4&&i3!=i4)
                    {
                        ma=max(ma, a[i1] & a[i2] & a[i3] &i4);
                    }
                }
            }
        }
    }
}
cout<<ma;
return 0;
}
