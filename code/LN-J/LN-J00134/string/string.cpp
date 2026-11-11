#include<bits/stdc++.h>
#define int long long
using namespace std;
struct str
{
    int len;
    char c;
};
int n,ans,l,r;
str s[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].len>>s[i].c;
    }
    l=0;
    r=n-1;
    while(l<n && r>=0 && l<r)
    {
        int ch=min(s[l].len,s[r].len);
        if(s[l].c!=s[r].c)
            ans+=ch;
        s[l].len-=ch;
        s[r].len-=ch;
        if(s[l].len==0)
            l++;
        if(s[r].len==0)
            r--;
    }
    cout<<ans;
    return 0;
}
