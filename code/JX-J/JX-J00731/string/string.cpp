#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s,s1;
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        for(int j=1;j<=a;j++) s+=b;
    }
    int len=s.size();
    while(len--)
    {
        s1+=s[len];
    }
    if(s1==s)
    {
        cout<<cnt;
        return 0;
    }
    for(int i=0;i<=s.size()/2-1;i++)
    {
        if(s[i]!=s[s.size()-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
