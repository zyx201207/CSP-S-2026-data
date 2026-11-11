#include<bits/stdc++.h>
using namespace std;
int a[500001];
int s[500001];
int d[500001];
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m,j=1,f=0,ma=0,w;
cin>>n>>m;
for(int i=1;i<=n;i++)
    {
    cin>>a[i];
    }
sort(a+1,a+n+1);
for(int i=1;i<=n;i++)
    {
    if(a[i]!=a[i+1])
        {
        s[j]=s[j]+1;
        d[j]=a[i];
        j++;
        }
    else
        {
        s[j]=s[j]+1;
        }
    }
if(m==0)
    {
    sort(s+1,s+1+j);
    cout<<s[j];
    return 0;
    }
for(int i=1;i<j;i++)
    {
    if(s[i]<=s[i+1])
        {
        ma=s[i+1];
        f=d[i+1];
        }
    else
        {
        ma=s[i];
        f=d[i];
        }
    }
for(int i=i;i>=1;i--)
   {
   if(m>=f-a[i])
        {
        a[i]=f;
        m=m-f+a[i];
        if(m==0)
          break;
        }
    }
for(int i=1;i<=n;i++)
    {
    if(a[i]!=a[i+1])
        {
        s[j]=s[j]+1;
        d[j]=a[i];
        j++;
        }
    else
        {
        s[j]=s[j]+1;
        }
    }
sort(s+1,s+1+j);
cout<<s[j];
return 0;
}
