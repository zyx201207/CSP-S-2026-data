#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int  n,a[200005];
    long long ans=0,cnt=0;
    char c[200005];
    string s="",s1="",s2="";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=a[i];
        cin>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    for(long long i=0;i<(ans/2);i++)
    {
        s1+=s[i];
        s2+=s[ans-1-i];
    }
    for(long long i=0;i<ans;i++)
    {
        if(s1[i]!=s2[i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

