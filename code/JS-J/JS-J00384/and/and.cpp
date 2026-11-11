#include<iostream>
#include<cstring>
#include<fstream>
typedef long long ll;
const ll maxn=2e5+5;
ll a[maxn];
ll ok[maxn],nok[maxn],offset=0;
int main()
{
    std::freopen("and.in","r",stdin);
    std::freopen("and.out","w",stdout);
    //std::cout<<(1<<0);
    ll n,m;
    std::cin>>n>>m;
    for(ll i=1;i<=n;i++)
        std::cin>>a[i];
    ll dig=35,ans=0;
    while(dig>=0)
    {
        ll cnt=0;
        for(ll i=1;i<=n;i++)
        {
            if((ok[i]==offset)&&(a[i]&(1LL<<dig)))
            {
                cnt++;
                nok[i]=offset+1;
            }
        }
        //std::cout<<(1LL<<dig)<<" "<<cnt<<" "<<offset<<"\n";
        if(cnt>=m)
        {
            ans=(ans|(1LL<<dig));
            for(int i=1;i<=n;i++)
                ok[i]=nok[i];
            offset++;
        }
        dig--;
    }
    std::cout<<ans;
    return 0;
}
