#include <bits/stdc++.h>
using namespace std;
bool del[200005];
int n,m,a[200005],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=30,cnt;i>=0;i--)
    {
        cnt=0;
        for(int j=1;j<=n;j++) if(!del[j]) cnt+=((a[j]>>i)&1);
        if(cnt>=m)
        {
            ans+=(1<<i);
            for(int j=1;j<=n;j++) if(!((a[j]>>i)&1)) del[j]=true;
        }
    }
    cout << ans;
}
