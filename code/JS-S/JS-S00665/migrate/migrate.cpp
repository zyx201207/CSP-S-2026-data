#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,d;
int c,t;
int pos[2000010];
int lstz[2000010];
int lsty[2000010];
int dlz[2000010];
int dly[2000010];
int ans=0;
int read()
{
    char c=getchar();
    int x=0;
    int f=1;
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') 
    {
        x = x*10+c-'0';
        c = getchar();
    }
    return x*f;
}
void write(int x)
{
    if(x<0) {
        putchar('-');
        write(-x);
    }
    else if(x<=9)
    {
        putchar(x+'0');       
    }
    else
    {
        write(x/10);
        putchar(x%10+'0');
    }
    return;
}
signed main()
{
    freopen("migrate3.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
    t=read();
    while(t--)
    {
        n=read();
        d=read();
        for(int i=1;i<=n;i++)
        {
            pos[i] = read();
            lstz[i]=0;
            lsty[i]=0;
            dlz[i]=0;
            dly[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            int l = 1,r = i;
            while(l < r)
            {
                int mid = (l+r) >> 1;
                if(pos[i]-pos[mid] <= d) r = mid;
                else l = mid+1;
            }
            lstz[i] = l;
        }
        for(int i=n;i>=1;i--)
        {
            int l = i,r=n;
            while(l<r)
            {
                int mid = (l+r+1) >> 1;
                if(pos[mid]-pos[i]<=d) l = mid;
                else r = mid-1;
            }
            lsty[i] = r;
        }
        for(int i=1;i<=n;i++)
        {
            if(lstz[i]!=i)
            {
                int tl = lstz[i];
                if(tl!=1)
                {
                    if(lstz[tl]!=lstz[tl+1])
                    {
                        dlz[i] = lstz[tl+1]-lstz[tl] + dlz[tl];
                    }
                }
            }
        }
        for(int i=n;i>=1;i--)
        {
            if(lsty[i]!=i)
            {
                int tl = lsty[i];
                if(tl!=n)
                {
                    if(lsty[tl]!=lsty[tl-1])
                    {
                        dly[i] = lsty[tl]-lsty[tl-1] + dly[tl];
                    }
                }
            }
        }
        ans=0; 
        for(int i=1;i+3<=n;i++)
        {
            if(pos[i+1]-pos[i]<=d&&pos[i+2]-pos[i]<=d&&pos[i+3]-pos[i+1]<=d&&pos[i+3]-pos[i+2]<=d&&pos[i+3]-pos[i] > d)
            { 
                int lgs = dlz[i] + lstz[i+1]-lstz[i] + 1;
                int rgs = dly[i+3] + lsty[i+3] - lsty[i+2] + 1;
                ans += lgs*rgs;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}