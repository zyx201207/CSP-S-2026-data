#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t;
ll x[N];
ll dp[N];
int to[N];
deque<int> q;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++) to[i]=(upper_bound(x+1,x+n+1,x[i]+d)-x-1);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=1;
            p[i]=1;
            q.push_back(i);
            for(int j=i+1;j<=n;j++)
            {
                dp[j]=0;
                while((q.size() && j>to[q.front()]) || q.size()>2) q.pop_front();
                if(q.size()==1 && dp[q.front()]==2)
                {
                    dp[j]=2;
                    ans++;
                    q.push_back(j);
                }
                else if(q.size()==2 && dp[q.front()]==1 && dp[q.back()]==1)
                {
                    dp[j]=2;
                    ans++;
                    q.push_back(j);
                }
                else if(q.size()==1)
                {
                    dp[j]=1;
                    q.push_back(j);
                }
            }
            while(q.size()) q.pop_back();
        }
        cout<<ans<<"\n";
    }
    return 0;
}
