#include<bits/stdc++.h>
using namespace std;
long long ans,m,n;
pair<long long,long long>a[200001];
long long check(long long x)
{
    long long c=0;
    while(x)c+=x%2,x/=2;
    return c;
}
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.second!=b.second)return a.second>b.second;
    return a.first>b.first;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i].first,a[i].second=check(a[i].first);
    sort(a+1,a+n+1,cmp);
    ans=a[1].first;
    for(long long i=2;i<=m;i++)ans&=a[i].first;
    cout<<ans;
    return 0;
}
