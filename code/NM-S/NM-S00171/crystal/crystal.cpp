#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool cmp(int q){
    long long an=0;
    for(int i=1;i<=q;i++){

        an+=a[q]-a[i];
        if(an>m) return false;
    }
    if(an<=m) return true;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n,mid,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(cmp(mid)){
        	ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
