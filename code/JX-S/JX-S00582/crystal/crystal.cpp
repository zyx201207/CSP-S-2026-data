#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans=0;
long long m,a[N],b[N];
bool cmp(long aa,long bb){
    return aa<bb;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l+1<r){
            int mid=(l+r)/2;
            if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m){
                r=mid;
            }
            else {
                l=mid+1;
            }
        }
        r-=1;
        ans=max(ans,i-r+1);
    }
    cout<<ans<<'\n';
    return 0;
}
