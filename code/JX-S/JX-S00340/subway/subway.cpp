#include<bits/stdc++.h>
using namespace std;

struct train
{
    int len;
    vector<int> a;
    vector<int> t;
};
int yybm,n,m,d,q;
vector<train> xianlu;
vector<int> w;
vector<bool> used;

int findnum(int a,int num)
{
    for(int i=0;i<xianlu[num].a.size();i++)
    {
        if(xianlu[num].a[i]==a) return i;
    }
    return -1;
}

int dfs(int x,int y)
{
    if(x==y) return 0;
    int minn=2100000000;
    for(int i=0;i<n;i++)
    {
        int weizhi=findnum(x,i);
        if(weizhi!=-1)
        {
            vector<int> v;
            for(int j=0;j<xianlu[i].len;j++)
            {
                if(j==weizhi) continue;
                int next=xianlu[i].a[j];
                if(used[next]) continue;
                used[next]=1;
                v.push_back(next);
                minn=min(minn,xianlu[i].t[weizhi]+xianlu[i].t[j]+dfs(next,y));
                if(next==y) return minn;
            }
            for(int j:v)
            {
                used[j]=0;
            }
        }
    }
    return minn;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>yybm>>n>>m>>d>>q;
    w.resize(m);
    used.resize(m+1);
    for(int i=0;i<m;i++)
    {
        cin>>w[i];
    }
    xianlu.resize(n);
    for(int i=0;i<n;i++)
    {
        int len;
        cin>>len;
        xianlu[i].len=len;
        xianlu[i].a.resize(len);
        xianlu[i].t.resize(len);
        for(int j=0;j<len;j++)
        {
            cin>>xianlu[i].a[j]>>xianlu[i].t[j];
        }
    }
    for(int abab=0;abab<q;abab++)
    {
        int xr=1,yr=2;
        cin>>xr>>yr;
        used[xr]=1;
        cout<<dfs(xr,yr)+w[xr-1]+w[yr-1]<<endl;
        used[xr]=0;
    }
}
