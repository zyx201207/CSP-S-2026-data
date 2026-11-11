#include<bits/stdc++.h>
using namespace std;
long long js;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    bool bj=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=a[i-1])
            bj=1;
    }
    sort(a+1,a+n+1);
    if(bj==0)
    {
        for(int i=1;i<=n;i++)
        {
            a[i]=a[i-1]+a[i];
            if(m<a[i])
            {
                cout<<i;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    long long he=0,maxx=0;
    for(int i=1;i<=n;i++)
    {
        long long js=0;
        for(int j=1;j<=n;j++)
        {
            if(a[i]>=a[j])
            {
                he+=a[i]-a[j];
                js++;
            }
        }
        if(he<=m)
        {
            maxx=max(maxx,js);
        }
        he=0;
    }
    cout<<maxx;
    return 0;
}
