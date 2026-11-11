#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long sum[N];
bool cmp(long long a,long long b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<=r){
            int mid=(l+r)>>1;
            long long cnt=a[i]*(i-mid+1)-(sum[i]-sum[mid-1]);
            if(cnt<=m){
                ans=max(ans,i-mid+1);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
