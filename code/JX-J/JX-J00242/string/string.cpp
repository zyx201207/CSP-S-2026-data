#include<bits/stdc++.h>
using namespace std;
int main()
{
    //the system will crash when a[i]>100000000!!!------from the author of this program
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long ai;
        char ci;
        cin>>ai>>ci;
        for(int j=1;j<=ai;j++)
        {
            s+=ci;
        }
    }
    //string ok
    long long len=s.size();
    string s1,s2;
    if(len%2==1)
    {
        for(int i=0;i<=len/2;i++)
        {
            s1+=s[i];
        }
        for(int i=len-1;i>=len/2;i--)
        {
            s2+=s[i];
        }
    }
    else
    {
        for(int i=0;i<=len/2-1;i++)
        {
            s1+=s[i];
        }
        for(int i=len-1;i>=len/2;i--)
        {
            s2+=s[i];
        }
    }
    if(s1==s2)
    {
        cout<<0;
        return 0;
    }
    long long len1,cnt=0;
    len1=s1.size();
    for(int i=0;i<len1;i++)
    {
        if(s1[i]!=s2[i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
