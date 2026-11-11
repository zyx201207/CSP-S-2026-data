#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+10;
int c,T;
int n,d;
int x[MAXN];
int cnt,cntstep;
void dfs(int step,int pos,int toward)
{
    //cout<<step<<" "<<pos<<" "<<toward<<"\n";
    if(pos==toward)
    {
        if(step<cntstep)
        {
            cnt=1;
            cntstep=step;
        }
        else if(step==cntstep)
        {
            cnt++;
        }
        return;
    }
    if(step>=cntstep) return;
    for(int i=pos+1;i<=toward;i++)
    {
        if(x[i]-x[pos]>d) break;
        dfs(step+1,i,toward);
    }
}
void work()
{
    cin>>n>>d;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    if(n<=10)
    for(int L=1;L<=n;L++)
    {
        for(int R=L+3;R<=n;R++)
        {
            cnt=0;cntstep=INT_MAX;
            dfs(0,L,R);
            //cerr<<cnt<<endl;
            if(cnt==2) ans++;
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        work();
    }
    return 0;
}
//g++ -o test -O2 -std=c++14 -static migrate.cpp
//buhui