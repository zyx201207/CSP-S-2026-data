#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        s+=string(a,c);
    }
    int len=s.size(),cnt=0;
    if(len%2==0)
    {
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])cnt++;
        }
    }
    else
    {
        for(int i=0,j=s.size()-1;i!=j;i++,j--)
        {
            if(s[i]!=s[j])cnt++;
        }
    }
    cout<<cnt;
    return 0;
}