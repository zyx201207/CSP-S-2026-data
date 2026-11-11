#include<bits/stdc++.h>
using namespace std;
#define int long long
int sz[500005];//sz[i]表示第i堆石子的体积
bool cmp(int a,int b)
{
    return a>b;
}
signed main()
{
    freopen("crystal3.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>sz[i];
    }
    sort(sz+1,sz+n,cmp);
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        int save=m;
        int tmp=i+1;
        int bench=sz[i];
        //int cnt=1;???
        int cnt=0;
        while(save>=bench-sz[tmp] &&tmp<=n)//?
        {
            cnt++;
            save-=bench-sz[tmp];
            tmp++;
        }
        if(cnt>maxx)maxx=cnt;
    }
    cout<<maxx<<endl;
    return 0;
}