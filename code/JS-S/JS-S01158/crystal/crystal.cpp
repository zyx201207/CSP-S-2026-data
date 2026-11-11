#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a;i<b;i++)
#define int long long
#define pq priority_queue
#define pb push_back
int n,l,ans=1,r;
int nowsum,m;
vector<int> v,sufsum;
int getsum(int a,int b)
{
    return sufsum[b]-sufsum[a];
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    fore(i,0,n)
    {
        int p;
        cin>>p;
        v.pb(p);
    }
    sort(v.begin(),v.end());
    fore(i,0,n)
    {
        sufsum.pb(nowsum);
        nowsum+=v[i];
    }
    l=0;r=0;
    for(;r<n;r++)
    {
        if(getsum(l,r+1)+m>=(r-l+1)*v[r])
        {
            ans=max(ans,(r-l+1));
        }
        else{
            l++;
        }
    }
    cout<<ans;
    return 0;
}
