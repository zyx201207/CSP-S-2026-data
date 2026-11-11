
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        ans[i]=ans[i-1]+a[i];
    }
    int ma=0;
    a[0]=-1e12+10;
    for(int i=1;i<=n;i++){
        int l=0,r=i;
        while(l<=r-2){
            int mid=(l+r)>>1;
            if((i-mid+1)*a[i]-(ans[i]-ans[mid-1])<=m)r=mid;
            else l=mid;
        }
        ma=max(ma,i-r+1);
    }
    cout<<ma;
    return 0;
}
