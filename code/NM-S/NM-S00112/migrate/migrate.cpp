#include <stdio.h>
#include <cstdio>
#include<vector>
#include<algorithm>
#define gc getchar_unlocked
#define pc putchar_unlocked
using ll=long long;
using namespace std;
/*migrate*/
ll Read()
{
    ll a=0,s=1;int c=gc();
    while(c!='-'&&(c>'9'||c<'0')){if(c==EOF)return 0;c=gc();}
    if(c=='-')s=-1,c=gc();
    while(c<='9'&&c>='0')a=a*10+c-'0',c=gc();
    return  a*s;
}
void Write(ll x)/*no space*/
{
    if(x<0)pc('-'),x=-x;
    ll n=0;char c[25];
    do c[n++]=x%10+'0',x/=10; while(x);
    while(n--)pc(c[n]);
}
vector<ll>a;
ll dp[10010][10010];
bool reach(ll x,ll y,ll d)
{
    if(x==y)return false;
    if(abs(y-x)<=d)return true;
    return false;
}
void solve()
{
    a.clear();
    ll n=Read(),d=Read(),ans=0;
    a.push_back(0);
    for(int i=1;i<=n;i++){a.push_back(Read());}
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            ll cmt=0;
            for(int k=i;k<=j;k++)
            {
                if(reach(i,k,d)&&reach(k,j,d))cmt++;
            }
            if(cmt==2)ans++;
        }
    }
    Write(ans);pc('\n');
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    Read();
    ll T=Read();
    while(T--)
    {
        solve();
    }
    return 0;
}
