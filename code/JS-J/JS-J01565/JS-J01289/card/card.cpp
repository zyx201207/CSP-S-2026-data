#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a;
int ans[500005];
void dfs(int s)
{
    vector<int>t;

    for(int i=s;i<=n;++i)
    {bool f=0;
        for(int j=0;j<t.size();++j)
        {
            if(t[j]==a[i])
            {
                t.erase(t.begin()+j+1,t.end());
                f=1;
                break;
            }
        }
        if(!f) t.push_back(a[i]);
    }
    for(const int j:t)
    {
        if(j!=0);
       ans[j]++;
    }
    return;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1,ai;i<=n;++i)
    {
        cin>>ai;
        a.push_back(ai);
    }
    for(int i=0;i<n;++i)
    {
        dfs(i);
    }
     for(int i=1;i<=m;++i)
    {
       cout<<ans[i]<<' ';
    }
    return 0;
}
