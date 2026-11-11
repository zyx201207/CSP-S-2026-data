#include<bits/stdc++.h>
using namespace std;
const int N=5002;
long long c,q,n,d,dis[N][N],a[N],minn,cnt,ans,b[N];
bool h[N][N],hh[N][N];
int main()
{
    freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&q);
    while(q)
    {
        ans=0;
        memset(dis,0,sizeof(dis));
        memset(h,0,sizeof(h));
        memset(hh,0,sizeof(hh));
        scanf("%lld%lld",&n,&d);
        for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
        //for(long long i=1;i<=n;i++) cout<<a[i]+1000000000000000001<<" ";
        //cout<<"\n\n\n";
        for(long long i=1;i+2-1<=n;i++)
        {
            if(abs(a[i]-a[i+1])>d) h[i][i+1]=1;
            dis[i][i+1]=1;
        }
        for(long long len=3;len<=n;len++)
        {

            for(long long i=1;i+len-1<=n;i++)
            {
                long long j=i+len-1;
                if(abs(a[i]-a[j])<=d)
                {
                    dis[i][j]=1;
                    continue;
                }
                if(hh[i][j]) continue;
                //cout<<i<<" "<<j<<" "<<cnt<<"\n";
                minn=LLONG_MAX;
                cnt=1;
                memset(b,0,sizeof(b));

                for(int l=i+1;l<j;l++)
                {
                    if(h[i][l]||h[l][j])
                    {
                        h[i][j]=1;
                        break;
                    }
                    if(dis[i][l]+dis[l][j]==minn)
                    {
                        bool x=0;
                        for(int k=1;k<=cnt;k++)
                        {
                            if(dis[i][b[k]]+dis[b[k]][l]+dis[l][j]==minn)
                            {
                                x=1;
                                break;
                            }
                        }
                        if(x) continue;
                        else
                        {
                            cnt++;
                            b[cnt]=l;
                        }
                    }
                    if(dis[i][l]+dis[l][j]<minn)
                    {
                        minn=dis[i][l]+dis[l][j];
                        cnt=1;
                        b[cnt]=l;
                        //cout<<
                    }
                }
                dis[i][j]=minn;

                if(cnt==2)
                {
                    //cout<<"----------------\n";
                    //cout<<i<<" "<<j<<"\n";
                    /*cout<<i<<":"<<a[i]+1000000000000000001<<" "<<j<<":"<<a[j]+1000000000000000001<<""<<" "<<minn<<"\n";
                    for(int l=i+1;l<j;l++)
                    {
                        if(dis[i][l]+dis[l][j]==minn) cout<<i<<" "<<l<<" "<<j<<"\n";

                    }*/
                    long long ll1=b[1],rr1,prel=i,prer=j,ll,rr;
                    /*for(int l=j-1;l>=i;l--)
                    {
                        if(abs(a[l]-a[j])<=d&&abs(a[l-1]-a[j])>d)
                        {
                            rr1=l;
                            break;
                        }
                    }*/
                    prel=b[1];
                    for(int l=b[1]+1;l<=j-1;l++)
                    {
                        if(l==j-1)
                        {
                            if(abs(a[j]-a[prel])>d&&abs(a[l]-a[j])<=d) prel=l;
                            break;
                        }
                        if(abs(a[l]-a[prel])<=d&&abs(a[l+1]-a[prel])>d)
                        {
                            prel=l;
                        }

                    }
                    rr1=prel;
                    prel=b[2];
                    for(int l=b[2]+1;l<=j-1;l++)
                    {
                        if(l==j-1)
                        {
                            if(abs(a[j]-a[prel])>d&&abs(a[l]-a[j])<=d) prel=l;
                            break;
                        }
                        if(abs(a[l]-a[prel])<=d&&abs(a[l+1]-a[prel])>d)
                        {
                            prel=l;
                        }

                    }
                    rr1=max(rr1,prel);
                    ans++;
                    prel=i;
                    for(int o=i;o>=1;o--)
                    {
                        ll=ll1;
                        rr=rr1;
                        if(o==i)
                        {
                            prer=j;
                            for(int p=j;p<=n;p++)
                            {
                                if(o==i&&p==j) continue;
                                if(hh[o][p]) break;
                                if(abs(a[p]-a[rr])>d&&abs(a[p]-a[prer])<=d)
                                {
                                    rr=prer;
                                    prer=p;
                                    hh[o][p]=1;
                                    ans++;
                                    //cout<<o<<" "<<p<<"\n";
                                }
                                else break;
                            }
                        }
                        else
                        {
                            prer=j;
                            if(abs(a[o]-a[ll])>d&&abs(a[o]-a[prel])<=d&&!hh[o][j])
                            {
                                ll=prel;
                                prel=o;
                                hh[o][j]=1;
                                ans++;
                                //cout<<o<<" "<<j<<"\n";
                            }
                            else break;
                            for(int p=j+1;p<=n;p++)
                            {
                                //if(p==j) continue;
                                if(hh[o][p]) break;
                                if(abs(a[p]-a[rr])>d&&abs(a[p]-a[prer])<=d)
                                {
                                    rr=prer;
                                    prer=p;
                                    hh[o][p]=1;
                                    ans++;
                                    //cout<<o<<" "<<p<<"\n";
                                }
                                else break;
                            }
                        }

                    }
                }
            }
        }
        //cout<<dis[2][4]<<"\n";
        printf("%lld\n",ans);
        q--;
    }
    return 0;
}
