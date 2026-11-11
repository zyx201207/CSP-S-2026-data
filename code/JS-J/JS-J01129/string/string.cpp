#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=200010;
int n;
char c[N];
int a[N];
ll ans;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int now=-1,l=1,r=n;
    while(1)
    {
        if(l>=r)
            break;
        now=min(a[l],a[r]);
        if(c[l]!=c[r])
            ans+=now;
        a[l]-=now,a[r]-=now;
        if(a[l]==0)
            l++;
        if(a[r]==0)
            r--;
    }
    printf("%lld",ans);
    return 0;
}
