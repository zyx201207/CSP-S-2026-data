#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int n,m;
int ans=0;
bool check(int mid){
    int t=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=mid) break;
        if(t>m) break;
        t+=mid-a[i];

    }
    return t<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int r=1e18;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            res=mid;
        }else {
            r=mid-1;
        }
    }
    int t=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(res-a[i]>=0&&cnt+(res-a[i])<=m){
            t++;
            cnt+=res-a[i];
        }else{
            break;
        }
    }
    cout<<t;
    return 0;
}
