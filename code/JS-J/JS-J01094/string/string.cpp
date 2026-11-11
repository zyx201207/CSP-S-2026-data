#include<bits/stdc++.h>
using namespace std;
char s[100000010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int len=0;
    for(int i=0;i<n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        for(int j=0;j<a;j++)
        {
            s[len++]=b;
        }
    }
    int ans=0;
    for(int i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
