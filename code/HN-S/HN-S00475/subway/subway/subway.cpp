#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[500005];
int a[505][10005];
int t[505][10005];
vector<int> line[10005];
int dire[505][10005];
ll ans;
int add(int l1,int l2,int p,int q){
    return t[l1][dire[l1][p]]+t[l2][dire[l2][q]];
}
void dfs(int p,int q)
{
    int tans=0;
    for(int i:line[p])
    {
        for(int j=1;j<=k[i];j++)
        {
            if(a[i][j]==p)continue;
            int cnt=0;
            for(int k:line[a[i][j]])
                cnt++;
            if(cnt>=2)
            {
                ans+=add(i,i,a[i][j],p);
                for(int x:line[a[i][j]])
                    for(int y:line[q])
                        if(x==y)
                            ans+=add(x,y,a[i][j],q);
                        else
                        	dfs(a[i][j],q);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j];
            cin>>t[i][j];
            line[a[i][j]].push_back(i);
            dire[i][a[i][j]]=j;
        }
    }
    for(int k=1;k<=q;k++)
    {
        int s,e;
        cin>>s>>e;
        ans=w[s]+w[e];
        bool isone=false;
        for(int i:line[s])
        {
            for(int j:line[e])
            {
                if(i==j)
                {
                    ans+=add(i,j,s,e);
                    isone=true;
                }
            }
        }

        if(isone)
        {
            cout<<ans<<endl;
            continue;
        }
        dfs(s,e);
        cout<<ans<<endl;
    }
    return 0;
}
