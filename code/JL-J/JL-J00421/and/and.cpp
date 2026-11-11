#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int n,m,a[101000],t=0,s=2;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>a[i];

}
sort(a+1,a+1+n);
if(m==1)
{
    cout<<a[n];
    return 0;
}
t=a[n-1];
for(int i=1;i<=300000;i++)
{
    s*=2;
    if(t==s-1)
    {
        cout<<t;
        break;
    }
}
return 0;
}
t+=n%2*x;
x*=10;
n/=2;
