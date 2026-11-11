#include <bits/stdc++.h>
using namespace std;
int s[200010];
int n,m;
int mn=0;
void f(int cnt,int ret,int pre)
{
    if (cnt==m)
    {
        mn=max(mn,ret);
    }
    for (int j=pre+1; j<n; j++)
    {
        if (ret&s[j]!=0)
        {
            f(cnt+1,ret&s[j],j);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    if (m==1)
    {
        sort(s,s+n);
        cout<<s[n-1];
    }
    else if (m==2)
    {
        int mx=0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (i!=j)
                {
                    mx=max(mx,s[i]&s[j]);
                }
            }
        }
        cout<<mx;
    }
    else if (m==n)
    {
        int ret=s[0]&s[1];
        for (int i=1; i<n; i++)
        {
            ret&=s[i];
        }
        cout<<ret;
    }
    else
    {
        for (int i=0; i<n; i++)
        {
            f(1,s[i],i);
        }
        cout<<mn;
    }
    return 0;
}
