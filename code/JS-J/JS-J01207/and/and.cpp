#include<bits/stdc++.h>
using namespace std;
int change(int a)
{
    int k[10000];
    int i=0;
    while(a!=0)
    {
        k[i]=a%2;
        i++;
        a/=2;
        cout<<a<<' '<<i<<endl;
    }

    for(int j=i;j>=0;j--)
    {
        a+=k[j]*pow(10,j);
    }
    return a+'0';
}
int and(int m,string s,int n)
{
    for(int i=0;i<n;i++)
    {
        and(m,a[i],n)
        string [i]=n
    }


        }
int turn_change(int res)
{
    int ans=0;
    while(res==0)
    {
         ans+=(res%pow(10,i)-res/pow(10,i);
         i++;
         res=res%pow(10,i)-res/pow(10,i);

    }
}
int main()
{
    freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
    int n,m,a[10000],res;
    string s[10000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s[i]=change(a[i]);
    }
    if(n==1)
        cout<<a[0];
    if(n==2)
        cout<<max(a[1],a[2]);


    return 0;
}
