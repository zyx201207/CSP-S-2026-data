#include <bits/stdc++.h>
using namespace std;
long long c,tt,n,ans,k,t[4100][4100],shushu,shushushu,num[4100],maxx,maxxx,tem;
bool vis[4100];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>tt;
    while(tt--)
    {
        cin>>n>>k;
        ans=0;
        maxx=1;
        maxxx=1;
        tem=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                t[i][j]=0;
            }
            vis[i]=0;
            num[i]=0;
        }
        for(int i=1;i<=n-1;i++)
        {
            cin>>shushu>>shushushu;
            t[shushu][shushushu]=1;
            t[shushushu][shushu]=1;
            num[shushu]++;
            num[shushushu]++;
            if(maxx<num[shushu])
            {
                maxx=num[shushu];
                maxxx=shushu;
            }
            if(maxx<num[shushushu])
            {
                maxx=num[shushushu];
                maxxx=shushushu;
            }
        }
        if(k==2)
        {
            cout<<1<<endl;
            continue;
        }
        if(k==3 or k==4)
        {
            cout<<2<<endl;
            continue;
        }
        tem=maxx;
        for(int i=1;i<=100000;i++)
        {
            if(tem>k)
            {
                cout<<i+1<<endl;
                break;
            }
            for(int j=1;j<=n;j++)
            {
                if(t[maxxx][j] and !vis[j])
                {
                    tem+=num[j]-1;
                    vis[j]++;
                }
            }
        }
    }
    return 0;
}
