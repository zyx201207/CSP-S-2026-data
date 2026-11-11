#include<bits/stdc++.h>
using namespace std;
long long  a[200005];
int b[200005];//2n
int c[50];//2n max geshu
int w=0;
int A(int y)
{
    long long x=a[y];
    int ans=0;
    while(x>1)
    {
        x=x/2;
        ans++;
    }
    b[y]=ans;
    c[ans]++;
    w=max(w,ans);
    return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        A(i);
    }
    int yyw=0;
    long long ans=0;
    while(yyw==0)
    {
        if(c[w]==m)
        {
            int zs=0;
            for(int i=1;i<=n;i++)
            {

                if(b[i]==w)
                {
                    if(zs==0)
                    {
                        ans=a[i];
                        zs=1;
                    }
                    else
                        ans=ans&a[i];
                }
            }
            yyw=1;
        }
        if(c[w]>m)
        {
            int t=c[w];
            long long d[t];
            int dd=0;
            for(int i=1;i<=n;i++)
            {
                if(b[i]==w)
                {
                    d[dd]=a[i];
                    dd++;
                }
            }
            long long s[m],f[m];
            int yy=d[0];
            for(int i=1;i<m;i++)
            {
                yy=yy&d[i];
                f[i]=d[i];
            }
            for(int i=0;i<m;i++)
            {
                s[i]=yy;
            }
            for(int i=m;i<t;i++)
            {long long aaa,bbb,ccc,ddd,eee=0,fff;
                for(int j=0;j<m;j++)
                {

                    aaa=s[j]^f[j];
                    bbb=pow(2,w)-1;
                    aaa=aaa^bbb;
                    ccc=aaa&d[i];
                    if(ccc>s[j]&&eee<ccc)
                    {
                        eee=ccc;
                        fff=j;
                    }
                }
                s[fff]=eee;
                f[fff]=d[i];
            }
            for(int i=0;i<t;i++)
            {
                ans=max(ans,s[i]);
            }
                yyw=1;
        }


        w--;
    }

    cout<<ans;
	return 0;
}
