#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    string s1=s;
    reverse(s.begin(),s.end());
    if(s1==s)
    {
        cout<<0;
        return 0;
    }
    s=s1;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        reverse(s.begin(),s.end());
        if(s1[i]!=s[i])
        {
            s1[i]=s[i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
