#include<bits/stdc++.h>
using namespace std;
string l,t;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char s;
        cin>>a>>s;
        for(int j=1;j<=a;j++)
        {
            l+=s;
        }
    }
    int ls=l.size(),pl=(ls+1)/2;
    for(int i=ls-1;i>ls-pl;i--)
    {
        t+=l[i];
    }
    for(int i=0;i<pl-1;i++)
        if(l[i]!=t[i])cnt++;
    cout<<cnt;
    return 0;
}
