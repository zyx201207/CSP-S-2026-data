#include <bits/stdc++.h>
using namespace std;
char r[200005];
long long s[200005],o,p;
int n;
long long ans=0;
int j;
void henc(int a,int b,long long c)
{
    bool y=a>b;
    int cnt=1;
    long long k=c;
    if(y)
    {
        while(k>0)
        {
            if(k>s[a+cnt])
            {
                k-=a=s[a+cnt];
                s[a+cnt]=0;
                cnt++;
            }
            else
            {
                s[a+cnt]-=k;
                k=0;
            }
        }
    }
    else
    {
        while(k>0)
        {
            if(k>s[a-cnt])
            {
                k-=a=s[a-cnt];
                s[a-cnt]=0;
                cnt--;
            }
            else
            {
                s[a+cnt]-=k;
                k=0;
            }
        }
    }
}
void solvea()
{
    for(int i=1; i<=(n+1)/2; i++)
    {
        j=n-i+1;
        if(r[i]!=r[j])
        {
            ans++;
        }
    }
    cout<<ans;
}
void solvesmall()
{
    char y[100002];
    int cnt=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=s[i]; j++)
        {
            y[cnt]=r[i];
            cnt++;
        }
    }
    for(int i=1; i<=(cnt+1)/2; i++)
    {
        j=cnt-i+1;
        if(y[i]!=y[j])
        {
            ans++;
        }
    }
    cout<<ans;
}
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    bool a=1,sm=1;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i]>>r[i];
        if(s[i]!=1)
        {
            a=0;
        }
        if(s[i]>50)
        {
            sm=0;
        }
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }

    if(a)
    {
        solvea();
        return 0;
    }
    if(n<=2000&&sm)
    {
        solvesmall();
        return 0;
    }
    for(int i=1; i<=(n+1)/2; i++)
    {
        if(s[i]==0)
        {
            i++;
            continue;
        }
        j=n-i+1;
        if(s[i]==s[j]&&r[i]==r[j])
        {
            continue;
        }
        else if(s[i]==s[j])
        {
            ans+=s[i];
            r[i]=r[j];
        }
        else if(r[i]==r[j])
        {
            if(i!=(n+1)/2)
            {
                o=min(s[i],s[j]);
                ans+=max(s[i],s[j])-o;
                henc(i,j,max(s[i],s[j])-o);
            }
        }
        else
        {
            o=min(s[i],s[j]);
            p=max(s[i],s[j]);
            ans+=p;
            henc(i,j,p-o);
        }
    }
    cout<<ans;
    return 0;
}
