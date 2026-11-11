#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,x=1,cnt=0;
    long long m,a[500100];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(a[4]-a[3]==a[3]-a[2]&&a[3]-a[2]==a[2]-a[1])
    {
    long long cha=a[2]-a[1];
    while(m>=0)
    {
        m-=x*cha;
        cnt++;
        x++;
    }
    cout<<cnt;
    }
    sort(a+1,a+n+1);
    if(a[n]-a[1]<=m/5)
        cout<<n;

    return 0;
}
