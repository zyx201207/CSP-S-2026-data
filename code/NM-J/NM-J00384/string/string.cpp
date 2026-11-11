#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
string s,s1;
int len;

void re()
{
    for(int i=len-1;i>=0;i--)
    {
        s1+=s[i];
    }
    return;
}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        char m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            s+=m;
        }
    }
    len=s.length();
    re();
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]!=s1[i]) cnt++;
    }
    cout<<cnt/2;
    return 0;
}
