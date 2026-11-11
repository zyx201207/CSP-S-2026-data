#include<bits/stdc++.h>
using namespace std;
long long tt[5005];
int c,t;
int n;
long long d;
long long summ;
long long dnumm[5005];
bool cmp(long long aa,long long bb)
{
    return aa<bb;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c<=2)
    {
        for(int iitt=1;iitt<=t;iitt++)
        {
            summ=0;
            scanf("%d%lld",&n,&d);
            sort(tt+1,tt+n+1,cmp);
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&tt[i]);
            }
            long long numm;
            for(int i=1;i<=n-3;i++)
            {
                for(int j=i+3;j<=n;j++)
                {
                    numm=0;
                    for(int ki=i+1;ki<=j-1;ki++)
                    {
                        if(ki-i==1||tt[ki]-tt[i]<=d)
                        {
                            if(j-ki==1||tt[j]-tt[ki]<=d)
                            {
                                numm++;
                            }
                        }
                    }
                    if(numm==2) summ++;
                    if(numm==0)
                    {
                        for(int ki=i+1;ki<j-1;ki++)
                        {
                            for(int kj=ki+1;kj<=j-1;kj++)
                            if(ki-i==1||tt[ki]-tt[i]<=d)
                            {
                                if(kj-ki==1||tt[kj]-tt[ki]<=d)
                                {
                                    if(j-kj==1||tt[j]-tt[kj]<=d) numm++;
                                }
                            }
                        }
                    }
                }
            }
            printf("%lld\n",summ);
        }
    }

    else if(c<=6)
    {
        for(int iitt=1;iitt<=t;iitt++)
        {

            summ=0;
            scanf("%d%lld",&n,&d);
            for(int i=1;i<=n;i++) dnumm[i]=1;
            for(int i=1;i<=n;i++)
            {
                scanf("%lld",&tt[i]);
            }
            sort(tt+1,tt+n+1,cmp);
            for(int i=1;i<n;i++)
            {
                int j=i+1;
                while(tt[j]-tt[i]<=d) j++;
                j--;
                if(j==i||j==i+1) {dnumm[i+1]+=dnumm[i];continue;}
                for(int ki=j+1;ki<=n;ki++)
                {
                    int kj=ki-1;
                    bool pd=1;
                    long long dd=0;
                    while(pd)
                    {
                        dd+=d;
                        while(tt[ki]-tt[kj]<=dd) kj--;
                        kj++;
                    }
                }
            }

        }
    }
    return 0;
}
