

#include <bits/stdc++.h>
using namespace std;
int n;

char s[1000000],a;
long long c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int x=0;
    for(int i=0;i<n;i++)
    {
        cin>>c>>a;
        for(long long j=0;j<c;j++)
        {
            s[x]=(char)a;
            x++;
        }

    }
    string s1=(string)s;
    int p,p1;
    long long c=0;
    if(n==1)cout<<s1;
    else if(n==2)
    {
        p1=s1.size(),p=0;
        for(int i=0;i<=s1.size()/2+1;i++)
        {
            if(s1[p]!=s1[p1])c++;
            p++,p1--;
        }
    }
    else
    {
        p1=s1.size()-s1.size()/n,p=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=s1.size()/n+1;i++)
            {
                if(s1[p]!=s1[p1])c++;
                    p++,p1--;
            }
        }
    }
    cout<<c;
    return 0;
}

