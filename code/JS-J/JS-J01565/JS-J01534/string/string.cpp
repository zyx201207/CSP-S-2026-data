#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,g,ans=0;
int l=1,r=n;
string S;
struct node{
    int a;
    char c;
}s[N];

/*
void cmp()
{
    if(l==r || l>r || ) return;
    int ch=s[l].c-s[r].c;
    if(ch==0)
    {
        if(s[l].c!=s[r].c) ans+=s[l].a;
        l++,r--;
    }
    else if(ch>0)
    {
        if(s[l].c!=s[r].c) ans+=s[r].a,r--;
        if(s[l].c!=s[r].c)
    }
}
*/

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
        g=__gcd(s[i].a,g);
    }
    for(int i=1;i<=n;i++)
    {
        s[i].a/=g;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s[i].a;j++)
            S=S+s[i].c;
    }
    int k=S.size();
    for(int i=0;i<k/2;i++)
    {
        if(S[i-1]!=S[k-i-1]) ans++;
    }
    cout<<ans*g;
    return 0;
}
