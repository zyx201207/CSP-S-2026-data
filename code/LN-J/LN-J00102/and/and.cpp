#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        cin>>a[i];
    int ans=0,cnt=0;
    for(int j = 30;j >= 0;j--)
    {
        if(cnt>=m)
            ans|=(1<<j);
        cnt=0;
        for(int i = 1;i <= n;i++)
            if(a[i]&(1<<(j-1)))
                b[++cnt]=a[i];
        if(cnt>=m)
        {
            for(int i = 1;i <= cnt;i++)a[i]=b[i];
            n=cnt;
        }
    }
    cout<<ans;
    return 0;
}
