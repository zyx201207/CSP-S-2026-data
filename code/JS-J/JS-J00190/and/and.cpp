#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[31];
void dp(int x,int pos)
{
    if(pos==-1||x==m)
    {
        int ans=(1<<30)-1;
        for(int i=1;i<=m;i++)
            ans=(ans&a[i]);
        cout<<ans;
        return;
    }
    if(b[pos]>=m)
    {
        int p=0;
        for(int i=1;i<=x;i++)
        {
            if(a[i]&(1<<pos))
            {
                a[++p]=a[i];
            }
            else
            {
                int tp=a[i],tp1=0;
                while(tp&&tp1<=pos)
                {
                    if(tp%2)
                        b[tp1]--;
                    tp1++;
                    tp/=2;
                }
            }
        }
        dp(p,pos-1);
    }
    else
        dp(x,pos-1);
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int tp=a[i],p=0;
        while(tp)
        {
            if(tp%2)
                b[p]++;
            p++;
            tp/=2;
        }
    }
    dp(n,30);
    return 0;
}
