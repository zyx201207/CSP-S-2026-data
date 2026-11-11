#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long int n,m,c,d,p,ans,ans1,ans2,ans3;
long long int g[N];
struct dt{
       long long int u,v,w,y,x;
}a[N];
dt sum[N];
bool cnt[N];
int check(int l,int ci,int co,int cs)
{
    g[cs]=l;
    if(ci==co)return cs;
    if(sum[l].x!=co&&a[sum[l].x].x!=l) ans3=check(a[sum[l].x].x,sum[l].x,co,cs+1);
    else if(sum[l].x!=co&&a[sum[l].x].x==l) ans3=check(a[sum[l].x].y,sum[l].x,co,cs+1);
    else if(sum[l].x==co&&a[sum[l].y].x==l) ans3=check(a[sum[l].y].y,sum[l].y,co,cs+1);
    else ans3=check(a[sum[l].y].x,sum[l].y,co,cs+1);
    return ans3;
}
long long int dj(int l,int ci,int co,int cs)
{
    ans2=0;
    check(l,ci,co,cs);
    for(int i=0;i<check(l,ci,co,cs);i++)
    {
        ans2+=sum[g[i]].v+sum[g[i]].w;
    }
    return ans2;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u;
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        if(k==2)
        {

            for(int j=1;j<=k;j++)
            {
                long long int b;
                cin>>b;
                if(!cnt[b])
                {
                    cnt[b]=1;
                    cin>>a[b].v;
                    sum[i].x=b;
                    sum[i].x=a[b].v;
                    a[b].x=i;
                }
                else{
                        cin>>a[b].w;
                        sum[i].y=b;
                        sum[i].y=a[b].w;
                        a[b].y=i;
                }
            }
        }
    }
    for(int i=1;i<=p;i++)
    {
        int c,d;
        cin>>c>>d;
        ans1=a[c].u+a[d].u;
        ans=max(ans1+dj(a[c].x,c,d,0),ans1+dj(a[c].y,c,d,0));
        cout<<ans<<'\n';
    }
    return 0;
}
