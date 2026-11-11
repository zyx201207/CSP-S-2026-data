#include<bits/stdc++.h>
using namespace std;
int g,n,e=1,u=1,p=10000001,c[500010],cnt[500010],m,d,q,w[500010],k[500010],s1[500010],s2[500010];
struct A{
    vector<int> a,t;
};
vector<int> b[500010];
int turn[500010];
A h[500010];
void v(int x,int y,int sum)
{
    if(x==y)
    {
        if(sum<p)
        {
            p=sum;
        }
        return;
    }
    for(int i=0;i<b[x].size();i++)
    {
        for(int j=1;j<=e;j++)
        {
            if(y==b[x][i])
            {
                sum+=h[b[x][i]].t[0];
                if(sum<p)
                {
                    p=sum;
                }
                return;
            }
            if(turn[j]==b[x][i])
            {
                for(int z=0;z<h[turn[j]].t.size();z++)
                {
                    sum+=h[turn[j]].t[z];
                }
                v(turn[j],y,sum);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>g>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>s1[j]>>s2[j];
            h[i].a.push_back(s1[j]);
            h[s1[j]].t.push_back(s2[j]);
            cnt[s1[j]]++;
            if(j!=1)
            {
                for(int z=1;z<j;z++)
                {
                    b[s1[j]].push_back(s1[z]);
                    b[s1[z]].push_back(s1[j]);
                }
            }
        }
    }
    for(int i=1;i<=500000;i++)
    {
        if(cnt[i]>1)
        {
            turn[e]=i;
            e++;
        }
    }
    while(q--)
    {
        int x,y,sum=0;
        cin>>x>>y;
        sum+=(w[x]+w[y]+h[x].t[0]);
        v(x,y,0);
        cout<<sum+p<<endl;
    }
    return 0;
}

