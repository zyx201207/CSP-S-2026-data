# include<cstdio>
# include<iostream>
# include<algorithm>
# include<cstring>
using namespace std;
const long long maxn = 0x3f3f3f3f3f3f3f3f;
int c,t,n,cnt1,cnt2;
long long d,x[2000005],dis[305][305];
void dfs(int now,int step,int st,int ed)
{
    if(step>dis[st][ed])
    {
        if(now == ed)cnt1++;
        return;
    }
    for(int i = now+1;i<=n;i++)
    {
        if(x[i]-x[now]<=d)dfs(i,step+1,st,ed);
    }
    return;
}
void f()
{
    memset(dis,0x3f,sizeof(dis));
    cnt2 = 0;
    for(int i = 1;i<=n;i++)
    {
        dis[i][i] = 0;
    }
    for(int i = 1;i<n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            if(x[j]-x[i]<=d)
            {
                dis[i][j]=1;
                dis[j][i]=1;
            }
            else break;
        }
    }
    for(int k = 1;k<=n;k++)
    {
        for(int i = 1;i<k;i++)
        {
            for(int j = k+1;j<=n;j++)
            {
                if(dis[i][k] >= maxn || dis[k][j] >= maxn)continue;
                if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j] = dis[i][k]+dis[k][j];
                }
            }
        }
    }
    for(int i = 1;i<n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            cnt1 = 0;
            dfs(i,1,i,j);
            if(cnt1 == 2)cnt2++;
        }
    }
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
        }
        if(c<=10)
        {
            f();
            cout << cnt2 << endl;
        }
        else if(c >= 11 && c<=12)
        {
            if(x[2]-x[1]>d)
            {
                cout << 0 << endl;
                continue;
            }
            int a = d/(x[2]-x[1]);
            if(a == 1)
            {
                cout << 0 << endl;
                continue;
            }
            a = 2*a-1;
            cout << n-a << endl;
        }
    }
    return 0;
}
