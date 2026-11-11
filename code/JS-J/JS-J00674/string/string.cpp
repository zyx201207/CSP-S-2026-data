#include<bits/stdc++.h>
using namespace std;
string s,s1;
int a=0,n,b;
int main()
{
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b;
        cin>>s1;
        for(int j=1;j<=b;j++)
            s+=s1;
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
            a++;
    }
    cout<<a;
    return 0;
}
