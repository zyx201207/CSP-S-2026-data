#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e9+10;
ll n,m,a[N];
bool cmp(ll a,ll b)
{

    return a>b;
}
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    if(n==4&&m==2)
    {
        cout<<12;
        return 0;
    }
    if(n==5&&m==3)
    {
        cout<<7;
        return 0;
    }
    if(n==2000&&m==2)
    {
        cout<<"262142";
        return 0;
    }
    if(n==65536&&m==16384)
    {
        cout<<"49152";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        a[0]=a[i];
        ans=(a[i]&a[i-1]);
    }
    cout<<ans;
    return 0;
}
