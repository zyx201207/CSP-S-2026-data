#include<bits/stdc++.h>
using namespace std;
long long int cy[1000005],qz[1000005];
int m,n;
bool cmp(int a,int b){
return a<b;
}
void input()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",cy+i);
        //cout<<cy[i];
    }
    sort(cy+1,cy+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        qz[i]=qz[i-1]+cy[i];
    }
}
long long int givans(int l,int r)
{
    if(l==r) return 0;
    return cy[r]*(r-l+1)-(qz[r]-qz[l-1]);
}
bool able(int num)
{
    for(int i=num;i<=n;i++)
    {
        if(givans(i-num+1,i)<=m) return true;
    }
    return false;
}
void solve()
{
    int l=1,r=n,mid=(l+r+1)/2;
    while(l!=r)
    {
        if(able(mid)) l=mid,mid=(l+r+1)/2;
        else r=mid-1,mid=(l+r)/2;
    }
    cout<<mid;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    input();
    solve();
    return 0;
}
