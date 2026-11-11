#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[N],f[2][N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out"."w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=a[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(i==j) continue;
            f[2][i]=max(f[2][i],a[i]&a[j]);
            ans=max(ans,f[2][[i]);
        cout<<ans;
    if(m==1){
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }
    if(a==n){
        ans=a[i];
        for(int i=1;i<=n;i++) ans&=a[i];
        cout<<ans;
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        long long ans2=a[2];
        for(int i=3;i<=n;i++) ans2&=a[i];
        cout <<max(ans.ans2);
        return 0;
    }
    return 0;
}
