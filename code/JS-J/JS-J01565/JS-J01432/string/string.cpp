#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long ans;
struct str
{
    long long a;
    string c="0";
}s[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
        if(i>1&&s[i].c==s[i-1].c)
        {
            s[i-1].a+=s[i].a;
            i--;
            n--;
        }
    }
    r=n;
    while(l<r)
    {
        if(s[l].c!=s[r].c)
        {
            ans+=min(s[l].a,s[r].a);
        }
        if(s[l].a==s[r].a)
        {
            l++;
            r--;
        }
        else if(s[l].a>s[r].a)
        {
            s[l].a-=s[r].a;
            r--;
        }
        else
        {
            s[r].a-=s[l].a;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
