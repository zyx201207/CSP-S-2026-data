#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool f[35][N],dp[N];
vector<int> g[35];
int cnt[35];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        for(int j=0;j<=30;j++)
            if(a&(1<<j)) g[j].push_back(a);
    }
    int h=-1;
    for(int i=30;i>=0;i--)
        if((int)g[i].size()>=m)
        {
            h=i;
            break;
        }
    if(h==-1)
    {
        cout<<"0\n";
        return 0;
    }
    for(int i=0;i<(int)g[h].size();i++)
    {
        dp[i]=true;
        for(int j=0;j<=30;j++)
            if(g[h][i]&(1<<j))
            {
                cnt[j]++;
                f[j][i]=true;
            }
    }
    long long ans=(1<<h);
    for(int i=h-1;i>=0;i--)
        if(cnt[i]>=m)
        {
            int x=0;
            for(int j=0;j<(int)g[h].size();j++)
                if(dp[j]&&f[i][j]) x++; 
            if(x>=m)
            {
                ans+=(1<<i);
                for(int j=0;j<(int)g[h].size();j++)
                    if(!f[i][j]) dp[j]=false;
            }
        }
    cout<<ans<<'\n';
    return 0;
}