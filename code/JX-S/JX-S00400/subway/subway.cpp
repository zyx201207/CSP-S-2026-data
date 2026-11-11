#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500001];
int plan[100001][2];
int k[501];
int a[500001][2];
long long ans;
bool visit[501];

struct line
{
    int s;
    int v;
    long long last;
};

vector<line> st[501];
stack<line> sta;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int v=0;v<m;v++) scanf("%d",&w[v]);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&k[i]);
        for(int j=0;j<k[i];j++)
            {scanf("%d%d",&a[j][0],&a[j][1]);}
        for(int l=0;l<k[i]-2;l++){
            int x=a[l][0];
            for(int r=l+1;r<k[i]-1;r++)
            {
                int y=a[r][0],sum=a[l][1]+a[r][1];
                st[x].push_back({y,sum,0});
                st[y].push_back({x,sum,0});
            }
        }
    }
    for(int r=0;r<q;r++) scanf("%d%d",&plan[r][0],&plan[r][1]);
    long long last=0;
    ans=w[plan[0][0]]+w[plan[0][1]];
    for(int now=0;now<n;now++)
    {
        for(int i=0;i<st[now].size();i++)
        {
            if(!visit[st[now][i].s])
                sta.push({st[now][i].s,st[now][i].v,last+w[st[now][i].s]});
        }
        last=w[st[now][i].s];
    }
    ans+=w[st[now][i].s];
    printf("%lld\n",ans);
    return 0;
}
