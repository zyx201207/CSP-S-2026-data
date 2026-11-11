#include <bits/stdc++.h>
using namespace std;
int a[500010],cnt,n,m;
int maxn=INT_MIN;
int main()
{

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        int t=m,j=i-1,cnt=1;
        while(a[i]-a[j]<=t&&j>=1)
        {
                cnt++;
                t-=a[i]-a[j];
                j--;

        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;

}


