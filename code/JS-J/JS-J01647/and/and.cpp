#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll a[n+1],ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    for(int i=2;i<=m;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
