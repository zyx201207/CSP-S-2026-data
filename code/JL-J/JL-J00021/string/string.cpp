#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a[200005],sum=0;
    char s[200005];
    string m;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            m+=s[i];
        }
    }
    long long f;
    if(m.size()%2==1)
    {
        f=m.size()/2+1;
    }
    else
    {
        f=m.size()/2;
    }
    for(int i=0;i<f;i++)
    {
        if(m[i]!=m[m.size()-i-1])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
