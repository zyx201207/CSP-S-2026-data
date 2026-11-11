#include<bits/stdc++.h>
using namespace std;
int a[1000000];
char c[1000000];
string b;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            b+=c[i];
        }
    }
    for(long long i=0;i<b.size()/2;i++)
    {
        if(b[i]!=b[b.size()-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
}
