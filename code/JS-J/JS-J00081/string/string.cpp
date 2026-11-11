#include<bits/stdc++.h>
#define int long long
#define fastIO ios::sync_with_stdio(0),cout.tie(0),cout.tie(0)
using namespace std;
const int N=2e5+5;
int n,le,mid,ans,a[N];
char c[N];
struct node
{
    int l,r;
    char c;
}s[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    fastIO;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        s[i]={le+1,le+a[i],c[i]};
        le+=a[i];
    }
    if(le*n>1e8)
    {
        mid=(le+1)/2;
        int R=le,L=1;
        ans=le/2;
        int i=1,j=n;
        for(;i<=n&&j>=1;i++,j--)
        {
            if(s[i].l>mid) break;
            int li=s[i].r-s[i].l+1;
            int lj=s[j].r-s[j].l+1;
            //cout<<li<<" "<<lj<<"\n"<<L<<" "<<R<<"\n";
            if(le-R+lj<=li)
            {
                //cout<<"typ1 "<<s[i].c<<" "<<s[j].c<<"\n";
                if(s[j].c==s[i].c) ans-=min(li,lj)/*,cout<<"cylovefinn\n"*/;
                if(li<lj) L+=li,R-=li,s[i].l+=li,s[j].r-=li;
                else R-=lj,L+=lj,s[i].l+=lj,s[j].r-=lj;
                i--;
            }
            else if(L-1+li<=lj)
            {
                //cout<<"typ2 "<<s[i].c<<" "<<s[j].c<<"\n";
                if(s[i].c==s[j].c) ans-=min(li,lj)/*,cout<<"cylovefinn\n"*/;
                if(li<lj) L+=li,R-=li,s[i].l+=li,s[j].r-=li;
                else R-=lj,L+=lj,s[i].l+=lj,s[j].r-=lj;
                j++;
            }
            //cout<<i<<" "<<j<<" "<<L<<" "<<R<<" "<<ans<<"\n";
        }
    }
    else
    {
        string s="";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=a[i];j++)
                s+=c[i];
        }
        ans=le/2;
        for(int i=1;i<=le/2;i++)
            if(s[i-1]==s[le-i]) ans--;
    }
    cout<<ans;
    return 0;
}
