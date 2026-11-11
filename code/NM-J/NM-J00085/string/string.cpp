#include <bits/stdc++.h>
using namespace std;
long long n;
string a;
long long a1[100005]={};
string c[100005]={};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long t=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i]>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a1[i];j++)
        {
            a=a+c[j];
        }
        t=t+a1[i];
    }
    cout<<a<<endl;
    long long m=1;
    long long s=a.size();
    for(int i=1;i<=s;i++)
    {
        if(i!=1+s/2)
        {
            if(a[i]!=a[t+1-i])
                {
                    m++;
                    a[i]=a[t+1-i];
                }
        }
    }
    cout<<m<<endl;
    return 0;
}
