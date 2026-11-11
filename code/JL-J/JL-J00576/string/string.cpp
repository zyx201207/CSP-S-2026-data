#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],ans,h;
char c[200010];
struct st{
    long long num;
    char l;
};
st q1[200010],q2[200010];
long long t1,t2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        ans+=a[i];
    }
    long long t=0;
    bool ju=false;
    for(long long i=1;i<=n;i++)
    {
        t+=a[i];
        h++;
        if(t<=ans/2)
        {
            q1[h].num=a[i];
            q1[h].l=c[i];
        }
        else
        {
            if(t-a[i]<=ans/2)
            {
                q1[h].num=ans/2-(t-a[i]);
                q1[h].l=c[i];
                t1=h+1;
                h=1;
                if(ans%2==0) q2[h].num=t-ans/2;
                else q2[h].num=t-ans/2-1;
                q2[h].l=c[i];
            }
            else
            {
                q2[h].num=a[i];
                q2[h].l=c[i];
            }
        }
    }
    long long ra=0,rra=0,tt1=0;
    tt1=t1;
    st tq1[200010],tq2[200010];
    for(long long i=1;i<=t1-1;i++)
    {
        tq1[i].num=q1[i].num;
        tq1[i].l=q1[i].l;
    }
    for(long long i=1;i<=h;i++)
    {
        tq2[i].num=q2[i].num;
        tq2[i].l=q2[i].l;
    }
    for(long long i=1;i<=h;i++)
    {
        while(q2[i].num>=0)
        {
            t1--;
            if(q1[t1].l==q2[i].l)
            {
                if(q1[t1].num==q2[i].num)
                {
                    break;
                }
                else
                {
                    if(q1[t1].num>q2[i].num)
                    {
                        q1[t1].num-=q2[i].num;
                        t1++;
                        break;
                    }
                    else
                    {
                        q2[i].num-=q1[t1].num;
                    }
                }
            }
            else
            {
                if(q1[t1].num==q2[i].num)
                {
                    ra+=q1[t1].num;
                    break;
                }
                else
                {
                    if(q1[t1].num>q2[i].num)
                    {
                        q1[t1].num-=q2[i].num;
                        ra+=q2[i].num;
                        t1++;
                        break;
                    }
                    else
                    {
                        q2[i].num-=q1[t1].num;
                        ra+=q1[t1].num;
                    }
                }
            }
        }
    }
    h++;
    for(long long i=1;i<=tt1-1;i++)
    {
        while(tq1[i].num>=0)
        {
            h--;
            if(tq1[i].l==tq2[h].l)
            {
                if(tq1[i].num==tq2[h].num)
                {
                    break;
                }
                else
                {
                    if(tq1[i].num>tq2[h].num)
                    {
                        tq1[i].num-=tq2[h].num;
                    }
                    else
                    {
                        tq2[h].num-=tq1[i].num;
                        h++;
                        break;
                    }
                }
            }
            else//2 a 1 c
            {
                if(tq1[i].num==tq2[h].num)
                {
                    rra+=tq1[i].num;
                    break;
                }
                else
                {
                    if(tq1[i].num>tq2[h].num)
                    {

                        tq1[i].num-=tq2[h].num;
                        rra+=tq2[h].num;
                    }
                    else
                    {
                        tq2[h].num-=tq1[i].num;
                        rra+=tq1[i].num;
                        h++;
                        break;
                    }
                }
            }
        }
    }
    long long suc=min(ra,rra);
    cout<<suc<<endl;
    return 0;
}
