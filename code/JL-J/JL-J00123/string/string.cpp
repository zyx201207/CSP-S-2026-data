#include<cstdio>
#define int long long
using namespace std;
const int N=2e5+5,M=1e8+5;
int n,ans,k,l;
char ch[5],str[M],v;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%s",&l,ch);
        v=ch[0];
        for(int j=1;j<=l;j++) str[++k]=v;
    }
    str[k+1]='\0';
    for(int i=1,j=k;i<=j;i++,j--)
    {
        if(str[i]!=str[j]) ans++;
    }
    printf("%lld",ans);
}
