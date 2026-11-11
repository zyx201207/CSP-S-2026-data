#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,ans=0,sum=0;
const int N=5e5+5;
ll a[N];
bool fa=1,fb=1;
ll pre[N];
void sola()
{
    pre[0]=0;
    pre[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(m>=pre[i-1])
        {
            cout<<i;
            return ;
        }
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    fa=1,fb=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)fa=0;
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])fb=0;
    }
    if(fa||fb)
    {
        sola();
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        ll mm=m;
        ll cnt=i-1;
        sum=1;
        while(mm>0&&cnt>0)
        {
            mm=mm-a[i]+a[cnt];
            cnt--;
            sum++;
            if(mm<0)sum--;
        }
        ans=max(sum,ans);
    }
    cout<<ans<<'\n';
    return 0;
}
/*
5 5
1 2 4 8 9
*/