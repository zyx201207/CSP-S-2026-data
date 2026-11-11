#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,o,j,f;
char c;
string s,q;
struct node
{
    long long u;
    char v;
}a[21000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n<=2000)
    {
        while(n--)
        {
            cin>>m>>c;
            for(long long i=1;i<=m;i++)
            {
                s=s+c;
            }
        }
        k=s.length();
        for(long long i=0;i<=k/2;i++)
        {
            if(s[i]!=s[k-i-1])
            ans++;
        }
        cout<<ans;
    }
    else
    {
        while(n--)
        {
            cin>>m>>c;
            if(c==a[o].v)
            {
                a[o].u+=m;
            }
            else
            {
                a[++o].u=m;
                a[++o].v=c;
            }
        }
        f=o;
        while(j<=o/2+1)
        {
            if(a[j].v==a[f].v)
            {
                if(a[j].u>=a[f].u)
                a[j].u-=a[f].u,f--;
                else
                a[f].u-=a[j].u,j++;
            }
            else
            {
                ans+=min(a[j].u,a[f].u);
                if(a[j].u>=a[f].u)
                {
                    a[j].u-=a[f].u,f--;
                }
                else
                {
                    a[f].u-=a[j].u,j++;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}