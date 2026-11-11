#include<bits/stdc++.h>
using namespace std;
int n,a;
char b;
string s[114514],s1[114514];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int i,j,y=1,k;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(j=y;j<a+y;j++)
        {
            s[j]=b;
            s1[j]=b;
        }
        y+=a;
    }
    for(i=y/2+1;i<=y;i++)
    {
        s1[i]=s[y-i];
    }
    k=y;
    for(i=1;i<=y;i++)
    {
        if(s[i]==s1[i])k--;
    }
    cout<<k;
    return 0;
}
