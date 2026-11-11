#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e6+10;
int c,t,n;
int lb[N],rb[N];
ll d,ans,cnt,mnd;
ll x[N];
void search(int u,int tar,int stp)
{
    if(stp>mnd)return;
    if(u==tar)
    {
        if(stp<mnd)mnd = stp,cnt=1;
        else if(stp==mnd)cnt++;
        return;
    }
    if(tar<=rb[u])return search(tar,tar,stp+1);
    for(int i = rb[u];i>=u+1;i--)search(i,tar,stp+1);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        ans = 0;
        cin>>n>>d;
        for(int i = 1;i<=n;i++)cin>>x[i];
        int sl = 1,sr = 1;
        for(int i = 1;i<=n;i++)
        {
            while(sr<n&&x[sr+1]-x[i]<=d)sr++;
            while(sl<i&&x[i]-x[sl]>d)sl++;
            lb[i] = sl,rb[i] = sr;
        }
        for(int i = 1;i<=n;i++)
            for(int j = i+1;j<=n;j++)
            {
                mnd=LLONG_MAX,cnt=0,search(i,j,0);
                if(cnt==2)ans++;
            }
        cout<<ans<<"\n";
    }
    return 0;
}