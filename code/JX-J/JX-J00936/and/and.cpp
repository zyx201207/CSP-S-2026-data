#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
const long long MAXA=1LL<<31;
int n,m,cnt[__lg(MAXA)];
long long ans,maxa,andsa=MAXA-1,a[MAXN];
bool all2k_1=true;
void DFS(int now,int sy,long long ands)
{
    if(n-now+1<sy) return;
    if(sy==0)
    {
        ans=max(ans,ands);
        return;
    }
    DFS(now+1,sy-1,ands&a[now]);
    DFS(now+1,sy,ands);
}
inline int popcount(long long x)
{
    int res=0;
    while(x) res+=(x&1),x>>=1;
    return res;
}
inline long long lowbit(long long x){return x&-x;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i],maxa=max(maxa,a[i]),andsa&=a[i];
        for(int j=0;(1LL<<j)<=a[i];j++)
            if((a[i]>>j)&1) cnt[j]++;
        if(lowbit(a[i]+1)!=a[i]+1) all2k_1=false;
    }
    if(all2k_1)
    {
        for(int j=__lg(MAXA)-1;j>=0;j--)
            if(cnt[j]>=m){cout<<(1LL<<j+1)-1;break;}
        //Why I must use j+1?
    }
    else if(m==1) cout<<maxa;
    else if(m==n) cout<<andsa;
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(i!=j) ans=max(ans,a[i]&a[j]);
        cout<<ans;
    }
    else if(m==n-1)
    {
        int id=-1;
        for(int i=1;i<=n;i++)
        {
            int bi=popcount(a[i]),bid=popcount(a[id]);
            if(id==-1||(bi<bid||bi==bid&&a[i]<a[id])) id=i;
        }
        ans=MAXA-1;
        for(int i=1;i<=n;i++)
            if(i!=id) ans&=a[i];
        cout<<ans;
        //It is wrong, but it maybe can get the points, right?!
    }
    else DFS(0,m,MAXA-1),cout<<ans;
    return 0;
}
//wo xie bu lai aaaa!!! qwqqwqwqwqwq
//wo shi zako zako qwq
