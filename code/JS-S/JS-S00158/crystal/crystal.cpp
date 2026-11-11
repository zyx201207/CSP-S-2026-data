#include <bits/stdc++.h>

using namespace std;

const int MAXN=5e5+10;
long long INF=1e12+10;

int n;
long long m;

long long a[MAXN];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    long long pre=0;
    int lst=1;
    for(int i=1;i<=n;i++)
    {
        int len=i-lst+1;
        pre+=a[i];
        while(lst!=i&&pre+m<a[i]*len)
        {
            pre-=a[lst];
            len--;
            lst++;
        }
        ans=max(ans,len);
    }
    cout<<ans;
    return 0;
}
