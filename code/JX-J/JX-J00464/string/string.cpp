#include<bits/stdc++.h>
using namespace std;
string a;
int n,s[(int)2e5+8],sum,sum1;
char t[(int)2e5+8];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i]>>t[i];
        sum1+=s[i];
        for(int j=0;j<s[i];j++) a+=t[i];
    }
    bool o=0;
    for(int i=0;i<n-1;i++)
    {
        if(t[i]!=t[i+1]) o=1;
    }
    if(!o)
    {
        cout<<0;
        return 0;
    }
    if(sum1%2==0)
    {
        for(int i=0;i<sum1/2;i++)
        {
            if(a[i]!=a[sum1-i-1]) sum++;
        }
    }

    else
    {
        for(int i=0;i<(sum1-1)/2;i++)
        {
            if(a[i]!=a[sum1-i-1]) sum++;
        }
    }
    cout<<sum;
    return 0;
}
