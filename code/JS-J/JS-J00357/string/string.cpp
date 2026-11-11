#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s;
bool check(string s)
{
    string z,h;
    long long y=s.length();
    for(int i=0;i<=y/2-1;i++)
    {
        z=z+s[i];
    }
    if(y%2==1)
    {
        for(int i=y/2+1;i<=y-1;i++)
        {
            h=h+s[i];
        }
        reverse(h.begin(),h.end());
        if(h==z)return true;
        for(int i=0;i<=h.length()-1;i++)
        {
            if(h[i]!=z[i])ans++;
        }
        return false;
    }
    else
    {
        for(int i=y/2;i<=y-1;i++)
        {
            h=h+s[i];
        }
        reverse(h.begin(),h.end());
        if(h==z)return true;
        for(int i=0;i<=h.length()-1;i++)
        {
            if(h[i]!=z[i])ans++;
        }
        return false;
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++)
        {
            s=s+c;
        }
    }
    if(check(s))cout<<0;
    else
    {
        cout<<ans;
    }
    return 0;
}
