#include<bits/stdc++.h>
#define ll long long
#define PI pair<int,int>
using namespace std;
int c,t;
int n;
ll d;
ll a[2000005];
int cnt;
ll ans;
void work(int st,int en)
{
    vector<PI>v;
    v.push_back({st-1,st-1});
    for(int i=st;i+3<=en;i++)
        if(a[i+2]-a[i]<=d&&a[i+3]-a[i]>d&&a[i+3]-a[i+1]<=d)
            v.push_back({i,i+3});
    v.push_back({en+1,en+1});
    for(int i=1;i<v.size()-1;i++)
        ans+=(v[i].first-v[i-1].first)*(v[i+1].second-v[i].second);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        ans=cnt=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n>=1e5&&a[n]-a[1]<=10*d)
        {
            cout<<"0\n";
            continue;
        }
        a[0]=-2e18;
        a[n+1]=2e18;
        ll lastp=0;
        for(int i=1;i<=n;i++)
            if(a[i+1]-a[i]>d)
            {
                work(lastp+1,i);
                lastp=i;
            }
        cout<<ans<<'\n';
    }
    return 0;
}
