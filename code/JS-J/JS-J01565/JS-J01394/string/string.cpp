#include<bits/stdc++.h>
using namespace std;
long long n;
char c[200000002];
long long ans=0;
long long s=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long x=0;
        char y;
        cin>>x>>y;
        for(int j=s;j<s+x;j++)
        {
            c[j]=y;
        }
        s+=x;
    }
    for(int i=0;i<s/2;i++)
    {
        if(c[i]!=c[s-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
