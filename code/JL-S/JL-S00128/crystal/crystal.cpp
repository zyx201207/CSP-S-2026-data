#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500001];
int b[500001];
int cnt=0;
int l=0;
int r=0;
int maxx=0;
int d=0,s=0;
int flag;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    d=m;
    a[0]=-10000000;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i) flag=true;
        b[i]=1;
    }
    if(flag)
    {
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])
            {
                b[i]=b[i-1]+1;
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(maxx<b[i])
            {
                maxx=b[i];
            }
        }
        for(int i=2;i<=n;i++)
        {
            if(b[i]==maxx)
            {
                int x=i;
                s=maxx;
                while(m>0&&x<=n)
                {
                    if(i>b[x])
                    {
                        l=a[x]-a[x-b[x]];
                    }
                    else
                        l=1e9;
                    r=a[x+1]-a[x];
                    if(l>b[i]*r)
                    {
                        if(m>=b[i]*r)
                        {
                            m-=b[i]*r;
                            b[i]++;
                            s++;
                            x++;
                            //cout<<1<<endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        if(m>=l)
                        {
                            m-=l;
                            s++;
                            b[i]++;
                            //cout<<s<<' ';
                            //cout<<2<<endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                b[i]=maxx;
                m=d;
                //cout<<s<<endl;
                cnt=max(cnt,s);
            }
        }
        cout<<cnt;
    }
    else
    {
        int f=2;
        while(m>0)
        {
            m-=f;
            if(m!=0)
                f++;
        }
        cout<<f;
    }
    return 0;
}
