#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
int c,t;
int n,d;
int const N=2e5+5;
int a[N];
queue<pair<int,int> >que;
int cntt[N];
int calc(int x,int y)
{
    que.push(make_pair(x,0));
    while(!que.empty())
    {
        pair<int,int>tmp=que.front();
        que.pop();
        int np=tmp.first;
        if(np==y)cntt[tmp.second]++;
        for(int i=1;i<=n;i++)
        {
            if(np+i>y)break;
            if(a[np+i]-a[np]<=d)
            {
                que.push(make_pair(np+i,tmp.second+1));
            }
            else break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(cntt[i]!=0)
        {
            return cntt[i];
        }
    }
}
void solve()
{
    memset(cntt,0,sizeof cntt);
    cin>>n>>d;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(i+2>=j)continue;
            if(calc(i,j)==2)
            {
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        solve();
    }



    return 0;
}
