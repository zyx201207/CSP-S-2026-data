#include<bits/stdc++.h>
#define int long long
#define len (i-j+1)
using namespace std;
int n,m;
int a[1000000],b[1000000];
int j=1,ans=1,con;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        int tcon=con+(len-1)*(a[i]-a[i-1]);
        //cout<<i<<" "<<j<<":"<<tcon<<endl;
        while(tcon>m||tcon<-1e5)
        {
            tcon-=a[i]-a[j];j++;
        //cout<<i<<" "<<j<<":"<<tcon<<endl;
        }
        con=tcon;
        ans=max(len,ans);
    }
    cout<<ans;
    return 0;
}
