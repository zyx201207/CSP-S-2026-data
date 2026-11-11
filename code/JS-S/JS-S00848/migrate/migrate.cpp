#include<bits/stdc++.h>
using namespace std;
long long c,T,n,a[110],dp[1010][1010],st,ans;
bool check(int l,int r)
{

}
int main()
{
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        mesmet(dp,0,sizeof(dp));
        scanf("%lld%lld",&n,&st);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=1;i<=n-2;i++)
            for(int j=i+2;j<=n;j++)
            {
                if(check(i,j)==1) ans++;
            }
        cout<<endl;
    }
    return 0;
}
