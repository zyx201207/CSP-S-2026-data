#include <bits/stdc++.h>//C beifen
using namespace std;
#define int long long
const int mxn=2e6+10;
int n,d;
int x[mxn];
bool isa;
int isb;
int ans=2e6+5;
int cnt=0;//ci shu
void dfs(int p,int times)
{
    if(times>ans)return;
    if(p==n)
    {
        if(ans>times)cnt=0;
        ans=min(ans,times);
        if(ans==times)cnt++;
        return ;
    }
    //cout<<p<<" "<<times<<endl;//
    for(int i=p+1;i<=n;i++)
    {
        if(x[i]-x[p]<=d)dfs(i,times+1);
        else break;
    }
    return;
}
inline void solve()
{
    //clear
    isa=true;
    isb=-1;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        if(i>=3 and x[i]-x[i-1]!=x[2]-x[1])isa=false;
    }
    for(int i=1;i<=n;i++)
    {
        if(x[i]-x[1]<=d and x[n]-x[i]<=d)
        {
            isb=i;
            break;
        }
    }
    //fen zhi
    if(isa)//  = cha
    {
        int deltax=x[2]-x[1];
        if((x[2]-x[1])*2>d or d>=3*deltax)
        {
            cout<<0<<'\n';
            return ;
        }
        cout<<n-3<<'\n';
    }
    else if(isb!=-1)
    {
        if(x[n]-x[1]<=d)
        {
            cout<<0<<'\n';
            return ;
        }
        if(x[n]-x[1]==2*d)
        {
            cout<<0<<'\n';
            return ;
        }
        //d<x[n]-x[1]<2*d
        int ans=0;
        int len=4;
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            if(x[r]-x[l]<2*d and x[r]-x[l]>d)ans++;
        }
        cout<<ans<<'\n';
    }
    else//most baoli
    {
        int res=0;
        for(int i=1;i<=n;i++)
        {
            cnt=0;
            ans=2e6+10;
            dfs(i,0);
            res+=cnt;
        }
        cout<<res<<'\n';
    }
    return ;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1,c;
    cin>>c>>T;
    while(T--)solve();
    return 0;
}
