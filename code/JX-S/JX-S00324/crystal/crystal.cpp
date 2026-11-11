#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
long long a[maxn],m;
int n;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long jl=0;
    int id=1,ans=1;
    for(int i=2;i<=n;i++)
    {
        jl+=(a[i]-a[i-1])*(i-id);
        while(jl>m)
        {
            jl-=a[i]-a[id];
            id++;
        }
        ans=max(ans,i-id+1);
    }
    cout<<ans<<"\n";
    return 0;
}
