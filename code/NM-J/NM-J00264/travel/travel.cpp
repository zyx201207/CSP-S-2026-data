#include<bits/stdc++.h>
using namespace std;
int n,s1,t,w,v
int a[2000001];
char b[2000001];
int z,y,c;
char d;
int ans;
bool fl;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=2;i<=n;i++)
    {
        a[i]==a[i-1];
    }
    s1=a[n]/2+a[n]%2;
    t=1,w=a[n],z=1;y=n;
    for(int i=1;i<=n;i++)
    {
        if(t>s1)
        {
            break;
        }
        if(w>s1)
        {
            break;
        }
        if(c)
        {
            if(fl)
            {
                if(d!=b[y])
                {
                    ans=min(d,a[y]);
                }
            }
            else
            {
                if(d!=b[z])
                {
                    ans=min(c,a[z]);
                }
                if(c>a[z])
                {
                    yy=0;
                }
                c=max()
            }
        }
    }
    return 0;
}
