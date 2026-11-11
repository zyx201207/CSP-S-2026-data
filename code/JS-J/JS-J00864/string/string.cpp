#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
unsigned long long a[N],ans,cha,sum,suml,sumr,sumz;
char c[N];
void fun1()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    int l=1,r=n;
    while(l<r&&suml<sum/2)
    {
        if(a[l]<a[r])
        {
            cha=a[r]-a[l];
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            suml+=a[l];
            a[r]-=a[l];
            l++;
        }
        if(a[l]>a[r])
        {
            cha=a[l]-a[r];
            if(c[l]!=c[r])
            {
                ans+=a[r];
            }
            suml+=a[r];
            a[l]-=a[r];
            r--;
        }
        if(a[l]==a[r])
        {
            cha=0;
            if(c[l]!=c[r]) ans+=a[l];
            l++;
            r--;
        }
    }
    cout<<ans;
    return;
}
void fun2()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    int l=1,r=n;
    suml=1,sumr=1;
     while(sumz<sum/2)
     {
         if(c[l]!=c[r]) ans++;
         sumz++;
         suml++;
         sumr++;
         if(suml>a[l])
         {
             suml=1;
             l++;
         }
         if(sumr>a[r])
        {
            sumr=1;
            r--;
        }
     }
     cout<<ans;
    return;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    fun2();
    return 0;
}
