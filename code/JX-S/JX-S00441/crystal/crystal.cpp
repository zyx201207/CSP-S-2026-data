#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,temp=0,temp_ans=1;
long long a[500005],pre[500005],pre2[500005];
//ru guo ni kan dao zhe hang pin yin bing qie ba ta men pin chu lai le,na ni que shi hen wu liao.
//qwq
//mei ban fa zhi hui bao li.
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(long long i=2;i<=n;i++)
    {
        pre[i] = a[i]-a[i-1];
        pre2[i] = pre[i];
    }
    sort(pre2+2,pre2+n+1);
    if(pre2[2]==pre2[n])
    {
        long long len=pre2[2];
        while(temp+len<=m){
            ans++;
            temp+=len;
            len+=pre[2];
        }
        printf("%lld",ans);
        return 0;
    }
    for(long long i=2;i<=n;i++)
    {
        temp=0;
        temp_ans=1;
        for(long long j=i;temp+(pre[j]*temp_ans)<=m&&j<=n;j++)
        {
            temp += pre[j]*temp_ans;
            temp_ans++;
        }
        ans = max(ans,temp_ans);
    }
    printf("%lld",ans);
    return 0;
}
