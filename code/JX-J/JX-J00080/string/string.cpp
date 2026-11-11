#include<bits/stdc++.h>
using namespace std;

int main()
{
    freeopen("string.in","r",stdin);
    freeopen("string.out","w",stdout);
    string b[1000],c[10000],d;
    int a[10000],sum,s[1000];
    int n;
    for(int i=1;i<=n;i++)
    {
    cin>>a[i]>>b[i];
    sum+=a[i];
    }
    for(int i=1;i<=sum;i++)
    {
    for(int j=1;j<=a[i];j++)
    {
    c[j]=b[i];
    i++;
    }
    i--;
    }
    int cnt=0;
    for(int i=1;i<=sum/2+1;i++)
    {
        if(c[i]!=c[n+1-i])
        {
        cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
