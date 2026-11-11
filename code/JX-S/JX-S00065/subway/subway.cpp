#include <bits/stdc++.h>
using namespace std;
const int N=505;
typedef long long LL;
LL c,n,m,d,q;
LL w[N],k[N];
LL a[N][N],t[N][N];
LL x[N],y[N];
LL p[N];
bool road[N][N];
void solution(LL s,LL e)
{
    if(s==e)cout<<0<<'\n';
    LL sum=0;
    LL now=s;
    LL start=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i][1]==s)
        {
            start=i;
            break;
        }
    }
    sum+=w[now]+t[start][1];
    while(now!=e)
    {
        LL onow=now;
        now=p[now];
        if(now==e)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i][1]==onow)
                {
                    sum+=t[i][2];
                    sum+=w[now];
                    break;
                }
            }
            break;
        }
        else
        {
            bool flag1=0,flag2=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i][1]==now)
                {
                    sum+=t[i][1];
                    flag1=1;
                }
                if(a[i][2]==now)
                {
                    sum+=t[i][2];
                    flag2=1;
                }
                if(flag1&&flag2)break;
            }
        }
    }
    cout<<sum<<'\n';
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
        p[a[i][1]]=a[i][2];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
        solution(x[i],y[i]);
    }
    return 0;
}
