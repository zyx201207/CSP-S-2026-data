#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    long long n,m,num;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    char a;
    for(int i=1;i<=n;i++)
    {
        cin>>num>>a;
        for(int i=1;i<=num;i++)
        {
            s+=a;
        }
    }
    long long sum=s.size(),ans=0;
    for(int i=0;i<=(sum+1)/2;i++)
    {
        if(s[i]!=s[n-i-1])
        {
            ans++;
            s[i]=s[n-i-1];
        }
    }
    cout<<ans;
}
