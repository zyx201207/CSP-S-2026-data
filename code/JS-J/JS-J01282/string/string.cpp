#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    long long ans=0;
    cin>>n;
    string s,s1,s2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c;
        for(int j=0;j<a[i];j++)
        {
            s=s+c;
        }
        cnt+=a[i];
    }
    if(cnt%2==1)
    {
    for(int i=0;i<s.size()/2;i++)
    {
        s1=s1+s[i];
    }
    for(int i=s.size()-1;i>s.size()/2;i--)
    {
        s2=s2+s[i];
    }
    }
    if(cnt%2==0)
    {
    for(int i=0;i<s.size()/2;i++)
    {
        s1=s1+s[i];
    }
    for(int i=s.size()-1;i>=s.size()/2;i--)
    {
        s2=s2+s[i];
    }
    }
    for(int i=0;i<=s.size()/2;i++)
    {
        if(s1[i]!=s2[i])
            ans++;
    }
    cout<<ans;
    return 0;
}
