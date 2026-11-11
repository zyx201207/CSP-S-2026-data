#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;
    string s,c;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>c;
        for(int j=0;j<a;j++)
        {
            s+=c;
        }
    }
    string p;
    long long t;
    if(s.length()%2==0)
    {
        t=s.length()/2;
    }
    else
    {
        t=s.length()/2+1;
    }
    for(long long i=0;i<t;i++)
    {
        p+=s[i];
    }
    t=s.length()/2;
    for(long long i=t-1;i>=0;i--)
    {
        p+=s[i];
    }
    long long sum=0;
    for(long long i=0;i<p.length();i++)
    {
        if(p[i]!=s[i])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
