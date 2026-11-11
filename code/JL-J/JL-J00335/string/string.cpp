#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    long long n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long a;
        char c;
        cin>>a>>c;
        for(int i=0;i<a;i++)
        {
            s+=c;
        }
    }
    long long l=s.size();
    if(l%2==1)
    {
        long long mid=l/2;
        string s1;
        s1=s.substr(0,mid);
        char c=s[mid];
        string s2=s1+c+s1;
        for(int i=0;i<l;i++)
        {
            if(s[i]!=s2[i])
            {
                ans++;
            }
        }
    }else if(l%2==0){
        long long mid=l/2;
        string s1=s.substr(0,mid-1);
        char c=s[mid];
        string s2=s1+c+c+s1;
        for(int i=0;i<l;i++)
        {
            if(s[i]!=s2[i])
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
