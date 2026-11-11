#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
char b[200000005];
char s[200000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long t=0,sum=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        for(long long j=1;j<=a[i];j++)
        {
            s[j+t]=b[i];
        }
        t+=a[i];
    }
    for(long long i=1;i<=t/2;i++)
        {
            if(s[i]!=s[t-i+1])
            {
                sum++;
            }
        }
        cout<<sum;
    return 0;
}