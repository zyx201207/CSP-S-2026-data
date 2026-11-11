#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct node
{
    char c;
    ll a;
}s[N];
int n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n==2)
    {
        cout<<min(s[1].a,s[2].a);
        return 0;
    }
    int l=1,r=n,f=0;
    ll ans=0,k=s[1].a;
    char nc=s[1].c;
    while(l<r)
    {
        if(f==0)
        {
            if(nc!=s[r].c) ans+=min(k,s[r].a);
            if(k>s[r].a)
            {
                k-=s[r].a;
                r--;
            }
            else if(k<s[r].a)
            {
                k=s[r].a-k;
                f=1;
                nc=s[r].c;
                l++;
            }
            else
            {
                l++;
                r--;
                k=s[l].a;
                nc=s[l].c;
            }
        }
        else
        {
            if(nc!=s[l].c) ans+=min(k,s[l].a);
            if(k>s[l].a)
            {
                k-=s[l].a;
                l++;
            }
            else if(k<s[l].a)
            {
                k=s[l].a-k;
                f=0;
                nc=s[l].c;
                r--;
            }
            else
            {
                l++;
                r--;
                k=s[l].a;
                nc=s[l].c;
            }
        }
    }
    cout<<ans;
    return 0;
}