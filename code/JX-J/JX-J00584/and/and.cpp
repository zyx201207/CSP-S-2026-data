#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    if(n<=20000 && m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                cnt=max(cnt,a[i]&a[j]);
            }
        }
        cout<<cnt<<"\n";
        return 0;
    }
    int ans=a[1];
    for(int i=2;i<=m;i++)
    {
        ans=(ans&a[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
