#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
long long z;
string x;
string s1;
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {


        cin>>z;
        cin>>x;
        for(long long j=1;j<=z;j++)
        {

            s=s+x;
        }
    }
    for(int i=s.size()-1;i>=0;i--)
    {

        s1=s1+s[i];
    }
    for(int i=0;i<s.size();i++)
    {

        if(s1[i]!=s[i])
        {

            ans++;
        }
    }
    cout<<ans/2;

    return 0;
}
