#include <bits/stdc++.h>
using namespace std;
long long n;long long m;long long ans=0;
long long a[500010]={};long long b[10010][10010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++)
        cin>>a[i];
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            b[i][j]=max(a[i]-a[j],a[j]-a[i]);
        }
        sort(b[i],b[i]+n);
        long long standard=0;long long cnt=1;
        for(long long j=1;j<n;j++){
            standard = standard + b[i][j];
            if(standard<=m)
                cnt++;
            else
                break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
