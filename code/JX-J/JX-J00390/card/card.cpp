#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans[300005];
bool check[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(long long i=1;i<=n;i++)
    {
        vector<long long> v;
        memset(check,0,sizeof(check));
        for(long long j=i;j<=n;j++)
        {
            for(auto it = v.begin();it!=v.end();it++)
            {
                if(*it == a[j]) v.erase(it--,v.end());
            }
            v.push_back(a[j]);
        }
        for(long long j=0;j<v.size();j++)
        {
            if(check[v[j]] == 0){
                ans[v[j]]++;
                check[v[j]] = 1;
            }
        }
    }
    for(long long i=1;i<=m;i++)
    {
        printf("%lld ",ans[i]);
    }
    return 0;
}
