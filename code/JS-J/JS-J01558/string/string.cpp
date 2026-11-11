#include <bits/stdc++.h>
using namespace std;
long long n,ans=0;
struct node
{
    long long len;
    char ch;
}s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].len>>s[i].ch;
    }
    int l=1,r=n;
    while(l<r)
    {
        if(s[l].len>s[r].len)
        {
            if(s[l].ch!=s[r].ch)ans+=s[r].len;
            s[l].len-=s[r].len;
            r--;
        }
        else if(s[l].len<s[r].len)
        {
            if(s[l].ch!=s[r].ch)ans+=s[l].len;
            s[l].len=0;
            s[r].len-=s[l].len;
            l++;
        }
        else
        {
            if(s[l].ch!=s[r].ch)ans+=s[l].len;
            s[l].len=0;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
