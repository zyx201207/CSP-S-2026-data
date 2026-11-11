#include<bits/stdc++.h>
#define int long long
#define ls (p<<1)
#define rs (ls|1)
#define F first
#define S second
using namespace std;
void fileopen(string s)
{
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
int testcase,T;
namespace sub2
{
    bool check(){return testcase<=6;}
    int a[307];
    pair<int,int> dp[307][307];
    void solve()
    {
        memset(dp,0x3f,sizeof(dp));
        int n,d,x,i,j;
        cin>>n>>d;
        for(i=1;i<=n;i++)cin>>a[i];
        for(x=1;x<=n;x++)
        {
            dp[x][x]={0,1};
            for(i=x+1;i<=n;i++)
            {
                for(j=x;j<i;j++)
                {
                    if(a[j]+d<a[i])continue;
                    if(dp[x][j].F==dp[x][i].F-1)dp[x][i].S+=dp[x][j].S;
                    else if(dp[x][j].F<dp[x][i].F-1)dp[x][i]=dp[x][j],dp[x][i].F++;
                }
            }
        }
        int ans=0;
        for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)if(dp[i][j].S==2)ans++;
        cout<<ans<<'\n';
    }
}
namespace subA
{
    bool check(){return testcase==11||testcase==12;}
    int a[2000003];
    void solve()
    {
        int n,d,i;
        cin>>n>>d;
        for(i=1;i<=n;i++)cin>>a[i];
        int e=a[2]-a[1],k=d/e-1;
        if(k<=0)cout<<"0\n";
        else cout<<max(0ll,n-(2*k+1))<<'\n';
    }
}
signed main()
{
    fileopen("migrate");
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>testcase>>T;
    while(T--)
    {
        if(sub2::check())
        {
            sub2::solve();
            continue;
        }
        if(subA::check())
        {
            subA::solve();
            continue;
        }
    }
    return 0;
}
/*
17:21 好像会了1~6+11~12（性质A）
定义dp[x][i]表示从第x个岛开始，飞到i岛的{最少步数，方案数}
则dp[x][x]={0,1}，其它初始值均为{inf,inf}
对于满足j岛可以到i岛的j，若dp[x][j].F=dp[x][i].F-1，则dp[x][i].S+=dp[x][j].S；若>，什么都不干；若<，则dp[x][i]=dp[x][j]，dp[x][i].F++
整体复杂度为O(n^3)

对于性质A，设公差为e，则两种情况产生，当且仅当存在k使得k*e与(k+1)*e均<=d，且(k+2)*e>d，此时相隔2k+1的两个点符合条件，则d/e-2<k<=d/e-1
此时答案为max(0,n-(2k+1))

17:42 严肃过了前四个大样例

期望32pts



Can you see the meaning inside yourself
Can you see the meaning in your darkness
Where are you now Have you gone away
Here now Is it just a lookalike
All of the world is slowly changing
In a way I cannot see from here

341799!!
*/
