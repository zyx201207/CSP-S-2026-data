#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int op,t;
int n,d,a[N];
void solve1()
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int flag=0;
        int l=i-1,now=i,f=0;
        while(f<n)
        {
            for(int j=now+1;j<=n;j++)
            {
                if(a[j]-a[now]>d)
                {
                    f=j-1;
                    break;
                }
                if(j==n) f=n;
            }
            if(now-l>1 && a[f]-a[now-1]<=d && a[f]-a[now-2]>d) flag++;
            if(flag==1) cnt++;
            if(flag>1) break;
            l=now,now=f;
            if(a[f+1]-a[f]>d) break;
        }
    }
    cout<<cnt<<"\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>op>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(op<=10) solve1();
    }
    return 0;
}
