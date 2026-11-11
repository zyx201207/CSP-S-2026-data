#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,ans=1;
ll a[N],m,ma=LONG_MIN,mi=LONG_MAX;
bool ch_B=true;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        ma=max(ma,a[i]);
        mi=min(mi,a[i]);
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) ch_B=false;
    }
    if(n==1)
    {
        printf("1");
        return 0;
    }
    if(ch_B)
    {
        ll cha=a[2]-a[1];
        m/=cha;
        ll must=(sqrt(1+m*8)-1)/2+1;
        printf("%lld",min(must,1LL*n));
        return 0;
    }

    for(ll i=mi;i<=ma;i++)
    {
        multiset<ll> dis;
        int ans_=0;
        ll al=0;
        for(int j=1;j<=n;j++) dis.insert(abs(a[j]-i));
        for(ll j:dis)
        {
            al+=j;
            if(al<=m) ans_++;
            else break;
        }
        ans=max(ans,ans_);
    }
    printf("%d",ans);
    return 0;
}
