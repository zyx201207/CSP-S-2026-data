#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int n,d,cnt=0,ans=0,ed,mn=0x3f;
const int maxn=2e6+10;
vector<int> g[maxn];
int a[maxn];

void dfs(int u,int sum)
{
    if(sum>mn) return;
    if(u==ed)
    {
        if(sum<mn)
        {
            cnt=1;mn=sum;
        }
        else if(sum==mn)
        {
            cnt++;
        }
        return;
    }
    for(int v:g[u])
    {
        dfs(v,sum+1);
    }
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%d",&n,&d);
        ans=0;
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if((a[j]-a[i])>d) break;
                g[i].push_back(j);
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                cnt=0;ed=j,mn=0x3f;
                dfs(i,0);
                if(cnt==2) ans++;
            }
        }
        cout << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

