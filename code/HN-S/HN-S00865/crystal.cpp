#include <bits/stdc++.h>
using namespace std;

int n,ans,nump;
long long m,a[500005];

inline int cou(int p,bool b)
{
    int cou=0,i=p;
    if(b)
    {
        while(i>=0 && a[i--]==a[p])cou++;
        return cou;
    }
    while(i<n && a[i++]==a[p])cou++;
    return cou;
}

inline long long qr()
{
    long long a=0;
    bool b=true;
    char c=getchar();
    while(c<'0' || c>'9')
    {
        if(c=='-')
            b=false;
        c=getchar();
    }
    while(c>='0' && c<='9')
    {
        a=a*10+c-'0';
        c=getchar();
    }
    if(b)
        return a;
    return a*(-1);
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    nump=0;
    ans=cou(nump,false);
    nump+=ans;
    while(nump<n)
    {
        int sna=cou(nump,false);
        int l=sna,nump1=nump-1;
        long long m1=m;
        while(nump1>=0 && a[nump]-a[nump1]<=m1)
        {
            int c=cou(nump1,true);
            if(m1/(a[nump]-a[nump1])>=c)
            {
                sna+=c;
                m1-=c*(a[nump]-a[nump1]);
                nump1-=c;
            }
            else
            {
                sna+=m1/(a[nump]-a[nump1]);
                m1=-1;
            }
        }
        ans=max(ans,sna);
        nump+=l;
    }
    cout<<ans;
    return 0;
}
