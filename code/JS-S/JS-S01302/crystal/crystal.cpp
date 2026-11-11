#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
int n,m;
int a[MAXN],ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int cnt=a[1];
    for(int i=1;i<=n;i++)
    {
        a[i]-=cnt;
    }
    int L=1,R=1;
    cnt=0;
    while(R<=n)
    {
        //cerr<<cnt<<' ';
        cnt=cnt+(R-L)*(a[R]-a[R-1]);
        while(L<R && cnt>m)
        {
            cnt=cnt-(a[R]-a[L]);
            L++;
        }
        ans=max(R-L+1,ans);
        R++;
    }
    cout<<ans<<'\n';
    return 0;
}
//g++ -o test -O2 -std=c++14 -static crystal.cpp
//two-pointer
//finished at 14:46
