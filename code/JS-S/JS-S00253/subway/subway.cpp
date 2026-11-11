#include <bits/stdc++.h>
using namespace std;

long long c,n,m,d,Q,k,ans=0,es;
vector <int> sl[500005];
vector <long long> tl[500005];
int ts[500005];
int num[500005];
void dfs(int s)
{
    if(s==es)
    {
        ans=num[s];
        return;
    }
    for(int i=0;i<sl[s].size();i++)
    {
        for(int i=0;i<=504;i++)
            num[i]=num[i];
        if(num[sl[s][i]]>=num[s]+tl[s][i])
        {
            num[sl[s][i]]=num[s]+tl[s][i];
            dfs(sl[s][i]);
        }
        else
            continue;
    }
    return;
}


int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(num,0x3f,500005);
    cin >> c >> n >> m >> d >> Q;
    for(int i=1;i<=m;i++)
    {
        cin >> ts[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> k;
        int a,t,b,t1;
        cin >> a >> t;
        for(int j=1;j<=k-1;j++)
        {
            b=a;
            t1=t;
            cin >> a >> t;
            t1+=t;
            sl[a].push_back(b);
            sl[b].push_back(a);
            tl[b].push_back(t1);
        }
        sl[a].push_back(b);
        sl[b].push_back(a);
    }
    while(Q--)
    {
        for(int i=0;i<=500004;i++)
            num[i]=0x3f3f3f3f;
        ans=0;
        int ss;
        cin >> ss >> es;
        ans+=ts[ss]+ts[es];
        num[ss]=ans;
        dfs(ss);
        cout << ans << endl;
    }
    return 0;
}
