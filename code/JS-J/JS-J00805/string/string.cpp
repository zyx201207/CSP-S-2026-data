#include<iostream>
#include<vector>
using namespace std;
bool q;
long long read()
{
    q=0;
    int c,d=0;
    long long x=0;
    c=getchar();
    while(c<'0'||c>'9')
    {
        c=getchar();
        if(c==-1)
        {
            q=1;
            return 0;
        }
        d=c;

    }
    while(c>='0'&&c<='9'||c==-1)
    {
        x=x*10+c-'0';
        c=getchar();
    }
    if(d=='-')
    {
        x*=-1;
    }
    return x;
}
struct nz{
    int a;
    char c;
};
vector<nz> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,l=0,r;
    long long ans=0;
    n=read();
    r=n-1;
    v=vector<nz>(n);
    for(int i=0;i<n;i++)
    {
        v[i].a=read();
        v[i].c=getchar();
    }
    while(l<r)
    {
        if(v[l].a>v[r].a)
        {
            if(v[l].c==v[r].c)
            {
                v[l].a-=v[r].a;
                v[r].a=0;
            }
            else
            {
                ans+=v[r].a;
                v[l].a-=v[r].a;
                v[r].a=0;
            }
        }
        else
        {
            if(v[l].c==v[r].c)
            {
                v[r].a-=v[l].a;
                v[l].a=0;
            }
            else
            {
                ans+=v[l].a;
                v[r].a-=v[l].a;
                v[l].a=0;
            }
        }
        if(v[l].a==0)
        {
            l++;
        }
        if(v[r].a==0)
        {
            r--;
        }
    }
    cout<<ans;
    return 0;
}
