#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long zd=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        zd=max(zd,a[i]);
    }
    if(m==1)
    {
        cout<<zd;
        return 0;
    }
    long long yy=a[1];
    for(int i=2;i<=n;i++)
    {
        yy=yy&a[i];
    }
    if(m==n)
    {
        cout<<yy;
        return 0;
    }
    if(m==2)
    {
        long long jg=-1;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                jg=max(jg,a[i-1]&a[i]);
            }
        }
        cout<<jg;
        return 0;
    }
    if(n-m==1)
    {
        long long zy=-1;
        long long dd=1;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j!=i)
                {
                  cnt++;
                  if(cnt==1)
                  {
                      dd=a[j];
                  }
                  else
                  {
                      dd=dd&a[j];
                  }
                }
            }
            zy=max(zy,dd);
            cnt=0;
        }
        cout<<zy;
        return 0;
    }
    if(n-m==2||m==2)
    {
        long long zy=-1;
        long long dd=1;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int k=i+1;k<=n;k++)
            {
                if(m==2)
                {
                    if(i!=k)
                    {
                        zy=max(zy,a[i]&a[k]);
                    }
                }
                else
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(j!=i&&j!=k)
                        {
                          cnt++;
                          if(cnt==1)
                          {
                              dd=a[j];
                          }
                          else
                          {
                              dd=dd&a[j];
                          }
                        }
                    }
                    zy=max(zy,dd);
                    cnt=0;
                }
            }
        }
        cout<<zy;
        return 0;
    }
    if(n-m==3||m==3)
    {
        long long zy=-1;
        long long dd=1;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int k=i+1;k<=n;k++)
            {
                for(int l=k+1;l<=n;l++)
                {
                    if(m==3)
                    {
                        zy=max(zy,a[i]&a[k]&a[l]);
                    }
                    else
                    {
                        for(int j=1;j<=n;j++)
                        {
                            if(j!=i&&j!=k&&j!=l)
                            {
                              cnt++;
                              if(cnt==1)
                              {
                                  dd=a[j];
                              }
                              else
                              {
                                  dd=dd&a[j];
                              }
                            }
                        }
                        zy=max(zy,dd);
                        cnt=0;
                    }
                }
            }
        }
        cout<<zy;
        return 0;
    }
    return 0;
}
