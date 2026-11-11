#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct node
{
    int a;
    char c;
}s[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i].a>>s[i].c;
    int l=1,r=n;
    while(l<r)
    {
        if(s[l].a>s[r].a)
        {
            s[l].a-=s[r].a;
            if(s[l].c!=s[r].c)ans+=s[r].a;
            s[r].a=0;
            r--;
        }
        else if(s[l].a<s[r].a)
        {
            s[r].a-=s[l].a;
            if(s[l].c!=s[r].c)ans+=s[l].a;
            s[l].a=0;
            l++;
        }
        else
        {
            if(s[l].c!=s[r].c)ans+=s[r].a;
            s[l].a=0;
            s[r].a=0;
            r--;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
