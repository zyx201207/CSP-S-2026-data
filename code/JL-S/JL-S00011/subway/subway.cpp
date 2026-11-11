#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int c,n,m,d,q,w[MAXN],num[MAXN][20],start,bound,sum[505];
long long ans;
bool flag1,flag2;
struct st
{
    int k,a[MAXN],t[MAXN];
}s[505];
struct pro
{
    int x,y;
}r[MAXN];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].k;
        for(int j=1;j<=s[i].k;j++)
        {
            cin>>s[i].a[j]>>s[i].t[j];
            num[s[i].a[j]][sum[i]++]=i;
        }
    }
    for(int i=1;i<=q;i++)
        cin>>r[i].x>>r[i].y;
    for(int i=1;i<=q;i++)
    {
        ans=0;
        ans+=w[r[i].x];
        for(int j=1;j<=n;j++)
            for(int l=1;l<=s[j].k;l++)
                if(s[j].a[l]==r[i].x)
                {
                    ans+=s[j].t[l];
                    start=j;
                }
        ans+=w[r[i].y];
        for(int j=1;j<=n;j++)
            for(int l=1;l<=s[j].k;l++)
                if(s[i].a[l]==r[i].y)
                {
                    ans+=s[i].t[l];
                    bound=j;
                }
        if(start!=bound)
        for(int j=1;j<=m;j++)
        {
            for(int l=1;l<=s[r[i].x].k;l++)
                if(num[j][l]==start)
                    flag1=true;
            for(int l=1;l<=s[r[i].x].k;l++)
                if(num[j][l]==bound)
                    flag2=true;
            if(flag1 && flag2)
            {
                ans+=s[start].t[j];
                ans+=s[bound].t[j];
                break;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
