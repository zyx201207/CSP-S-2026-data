#include <bits/stdc++.h>
using namespace std;
int n,a[100003];
string s[100003],b[10000008];
long long c;
int main()
{
    freopen("string1.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long c=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>s[i];
        for(int j=1;j<=a[i];j++)
        {
            b[c]=s[i];
            c++;
        }
    }
    int ans=0;
    for(int i=1;i<=c/2+1;i++)
    {
        int j=c-i+1;
        if(b[i]!=b[j])
            ans++;
    }
    cout<<ans;
    return 0;
}
