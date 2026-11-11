#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;char c;
    cin>>n;
    string s;
    for(long long i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    long long j=s.size();
    j=j-1;
    int p=0;
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]!=s[j])
        {
            p++;
            break;
        }
        j--;
    }
    long long m=0;j=s.size();j=j-1;
    if(p==0)
    {
        cout<<"0"<<endl;
    }
    else
    {
        for(long long i=0;i<s.size();i++)
        {
            if(s[i]!=s[j])
            {
                s[j]=s[i];
                m++;
            }
            j--;
        }
        cout<<m<<endl;
    }
    return 0;
}





























































































