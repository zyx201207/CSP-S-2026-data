#include <stdio.h>
#include <cstdio>
#include<vector>
#include<algorithm>
#define gc getchar_unlocked
#define pc putchar_unlocked
using ll=long long;
using namespace std;
/*crystal*/
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
ll m,n,mid,ans=0;
vector<ll> a,dj;
ll mng(ll i)
{
    if(a[i]==a[mid])return ans++;
    ll cha=(ll)abs(a[i]-a[mid]);
    if(cha>m) return 0;
    m-=cha;
    ans++;
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=Read(),m=Read();
    ll mm=m;
    a.push_back(0);
    dj.push_back(0);
    for(int i=1;i<=n;i++)
    {
        a.push_back(Read());
    }
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++)
    {
        dj.push_back((a[i]-a[i-1])*(i-1));
    }
    if(m==0)
    {
        ll cnt=1,ans=-1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])cnt++;
            else
            {
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        Write(ans);
        return 0;
    }
    bool flg=0;
    for(auto i:dj)
    {
        if(flg){Write(i);pc(' ');flg=1;break;}
        if(m-i<0){Write(i);pc(' ');flg=1;break;}
        else ans++,m-=i;
        //Write(i);pc('\n');
    }
    Write(ans-1);pc(' ');
    Write(m);
    return 0;
}
