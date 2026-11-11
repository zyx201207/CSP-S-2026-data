#include <bits/stdc++.h>
using namespace std;
long long a[500002];
int n,ans;
long long m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    long long mp=m;
    int l=1,r;
    ans=1;
    for(r=2;r<=n;r++){
        if(l==r)continue;
        int len=r-l+1;
        mp-=(len-1)*(a[r]-a[r-1]);
        while(mp<0){
           if(l==r)break;
           mp+=a[r]-a[l++];
        }
        if(r-l+1>ans)
        ans=r-l+1;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
