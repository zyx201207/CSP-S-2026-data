#include<bits/stdc++.h>
#define int long long
#define pig pair<long long,long long>
using namespace std;
long long qw[1000000],as[1000000],qw1[1000000],as1[1000][1000],lala[1000000],leile[1000000];
priority_queue<pig,vector<pig>,greater<pig>>qq;
vector<pair<long long,long long>>op[1000000];
void DJstar(long long z)
{
    long long x,c,v;
    memset(qw,0x3f,sizeof qw);
    memset(as,0,sizeof as);
    qq.push({0,z});
    qw[z]=0;
    while(qq.size()!=0)
    {
        x=qq.top().second;
        qq.pop();
        if(as[x]!=0)
        {
            continue;
        }
        as[x]=1;
        for(auto i:op[x])
        {
            if(qw[i.first]>qw[x]+i.second)
            {
                qw[i.first]=qw[x]+i.second;
                qq.push({qw[i.first],i.first});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long a,s,d,f,g,h,j,k,l,maxn=0;
    cin>>a;
    cin>>a>>s>>d>>f;
    for(int i=1;i<=s;i++)
    {
        cin>>qw1[i];
    }
    for(int i=1;i<=a;i++)
    {
        cin>>g;
        for(int j=1;j<=g;j++)
        {
            cin>>lala[j]>>as1[i][j];
            leile[lala[j]]++;
        }
        for(int j=1;j<g;j++)
        {
            if(leile[lala[j]]!=1)
            {
                op[lala[j]].push_back({lala[j+1],1LL});
            }
            else
            {
                op[lala[j]].push_back({lala[j+1],0LL});
            }
        }
    }
    while(f--)
    {
        cin>>g>>h;
        DJstar(g);
        cout<<qw1[g]+qw1[h]+as1[1][1]*2LL+(qw[h]!=0x3f3f3f3f3f3f3f3f)*qw[h]*2LL*as1[1][1]<<endl;
    }
}
//hao nan a,nan ku le  :(
//17:37wo lei le,tiao bu wan de dai ma
/*
0 2 4 20 2
1 3 6 9
2 1 3 2 3
2 3 3 4 3
1 2
3 4
*/
