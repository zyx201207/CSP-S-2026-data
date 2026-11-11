#include <bits/stdc++.h>
using namespace std;
int mx=INT_MIN;
int a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=a[1];i<=a[n];i++)
    {
        int ans=0;
        int cnt=0;
        for(int j=n;j>=1;j--)
        {
            if(i>=a[j]) {
                if(m>=cnt+(i-a[j]))
                {
                    cnt=cnt+(i-a[j]);
                    ans++;
                }
            }
        }
        mx=max(mx,ans);
    }
    cout<<mx<<endl;
    return 0;
}
