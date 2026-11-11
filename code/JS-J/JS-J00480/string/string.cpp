#include <bits/stdc++.h>
using namespace std;
string s;
char c;
long long i,L,ans=0,n,j,a,l,r,x,b[200005];
void gengxin()
{
    if(l>=r)
    {
        x=r,l-=r,r=0;
    }
    else
    {
        x=l,r-=l,l=0;
    }
    if(l==0)
    {
        i++;
        l=b[i];
    }
    if(r==0)
    {
        j--;
        r=b[j];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>c;
        b[i]=a;
        s+=c;
    }
    L=s.size();
    i=0,j=n-1;
    l=b[i],r=b[j];
    while(i<j)
    {
        if(s[i]==s[j])
        {
            gengxin();
        }
        else
        {
            gengxin();
            ans+=x;
        }
    }
    cout<<ans;
    return 0;
}
