#include<bits/stdc++.h>
using namespace std;
long long a[200086],sum=0,r=1,l;
char b[200086];
void f(int x)
{
    if(a[r]>=a[l])
    {
        a[r]-=a[l];
        sum+=a[l]*x;
        l-=1;
    }
    else
    {
        a[l]-=a[r];
        sum+=a[r]*x;
        a[r]=0;
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>l;
    for(long long i=1;i<=l;i++) cin>>a[i]>>b[i];
    while(r<l)
    {
        while(a[r]>0)
        {
            if(b[r]==b[l])
                f(0);
            else
                f(1);
        }
        r+=1;
    }
    cout<<sum<<endl;
    return 0;
}


