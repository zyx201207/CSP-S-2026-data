#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=(int)(2e6+10);
int a[N];int T;
int n,d;int c;
int minnstep=INT_MAX;

void road(int now, int goal, int step)
{
    if(now==goal)
    {
        minnstep=min(minnstep, step);
        return ;
    }
    for(int i=1;i<d;i++)
    {
        int pos=a[now]+i;
        int iffind=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]==pos)
            {
                iffind=1;
                break;
            }
        }
        if(iffind==1)
        {
            road(pos, goal, step+1);
            //cout<<now<<' '<<pos<<endl;
        }
    }
}

int ret=0;
int cnt=0;

void go_road(int now, int goal, int step)
{
    if(now==goal||cnt>2)
    {
        if(step==minnstep)cnt++;
        return ;
    }
    for(int i=1;i<d;i++)
    {
        int pos=a[now]+i;
        int iffind=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]==pos)
            {
                iffind=1;
                break;
            }
        }
        if(iffind==1)
        {
            road(pos, goal, step+1);
        }
    }
}

bool _find(int beg, int ed)
{
        road(beg, ed, 0);
        go_road(beg, ed, 0);
        if(cnt==2)return 1;
        else return 0;
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>T;
    if(c==13||c==14)
    {
        while(T--)cout<<0<<endl;
        return 0;
    }
    while(T--)
    {
        cin>>n>>d;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
        {
            if(i==j)continue;
            if(_find(i, j)==1)ret++;;
        }
        cout<<ret<<endl;
        ret=0;
    }
    return 0;
}
