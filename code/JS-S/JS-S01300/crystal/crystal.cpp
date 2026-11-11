#include<bits/stdc++.h>
using namespace std;
long long t[500005];
int n;
long long m,km;
int numm=1;
int summ=1;
bool cmp(long long a,long long b)
{
    return a<b;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&t[i]);
    }
    sort(t+1,t+n+1,cmp);
    km=0;
    for(int i=2;i<=n;i++)
    {
        km+=(t[i]-t[i-1])*(long long)numm;
        numm++;
        if(km>m)
        {
            while(km>m)
            {
                numm--;
                km-=t[i]-t[i-numm];
            }
        }
        summ=max(summ,numm);
    }
    printf("%d",summ);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
