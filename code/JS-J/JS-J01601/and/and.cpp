#include<bits/stdc++.h>
using namespace std;
const int N=200009;
bool b[N][35],h[N],ans[35];
long long a,n,m,cnt,sum;
int bit,bitmax=0;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++) h[i]=1;
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        bit=0;
        while(a)
        {
            bit++;
            b[i][bit]=a%2;
            a/=2;
        }
        bitmax=max(bit,bitmax);
    }
    for(int i=bitmax;i>=1;i--)
    {
        cnt=0;
        for(long long j=1;j<=n;j++) if(h[j]&&b[j][i]) cnt++;
        if(cnt>=m)
        {
            for(long long j=1;j<=n;j++) if(h[j]&&(!b[j][i])) h[j]=0;
            ans[i]=1;
        }
    }
    for(int i=bitmax;i>=1;i--)
    {
        sum=sum*2;
        sum+=ans[i];
    }
    printf("%lld",sum);
    return 0;
}
