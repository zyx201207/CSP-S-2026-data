#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int sum[500005];
int ans=1;
signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr),cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum[1]=a[1];
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n,mid=0;
    while(l<=r){
        bool f=0;
        mid=(l+r)>>1;
        for(int i=1;i<=n-mid+1;i++){
            int ed=i+mid-1;
            int s=sum[ed]-sum[i-1];
            int ss=a[ed]*mid-s;
            if(ss<=m){
                ans=mid;f=1;
                break;
            }
        }
        if(!f){
            r=mid-1;
        }else l=mid+1;
    }
    cout<<ans;
}