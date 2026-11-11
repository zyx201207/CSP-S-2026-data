#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m,a[N],cnt[N];
bool fd(long long x){
    for(int i=1;i<=n-x+1;i++){
        int l=i,r=i+x-1;
        if((x-1)*a[r]-cnt[r-1]+cnt[l-1]<=m)
            return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        cnt[i]=cnt[i-1]+a[i];
    int l=1,r=n;
    while(l<r-1){
        int mid=(l+r)/2;
        if(fd(mid))l=mid;
        else r=mid;
    }
    cout<<l<<"\n";
    return 0;
}
